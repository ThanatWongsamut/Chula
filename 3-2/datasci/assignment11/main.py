import streamlit as st
import pandas as pd
import altair as alt
import pydeck as pdk

# Load the dataset
@st.cache_data
def load_data():
    data = pd.read_csv('./RainDaily_Tabular.csv')
    data['date'] = pd.to_datetime(data['date'])
    return data

data = load_data()

# Sidebar - Province selection
province_list = data['province'].unique().tolist()
province_selection = st.sidebar.multiselect('Select Province(s)', province_list, default=province_list)

# Sidebar - Date selection
min_date = data['date'].min().date()  # Ensure we're working with python date objects
max_date = data['date'].max().date()  # Ensure we're working with python date objects

date_options = [date.date() for date in pd.date_range(min_date, max_date)]  # List of date objects
date_selection = st.sidebar.select_slider('Select Date Range',
                                          options=date_options,
                                          value=(min_date, max_date))

# Filtering data by province and date
# Convert date_selection to pandas timestamps to filter the dataframe
start_date, end_date = pd.to_datetime(date_selection[0]), pd.to_datetime(date_selection[1])
filtered_data = data[(data['province'].isin(province_selection)) &
                     (data['date'].dt.date.between(start_date.date(), end_date.date()))].copy()

# Bar chart by province
st.subheader("Average rain by province")
bar_chart_data = filtered_data.groupby('province')['rain'].mean().reset_index()
bar_chart = alt.Chart(bar_chart_data).mark_bar().encode(
    x=alt.X('province:N', sort='-y'),
    y=alt.Y('rain:Q', title='Average Rainfall (mm)'),
    tooltip=['province', 'rain']
).interactive()
st.altair_chart(bar_chart, use_container_width=True)

# Line chart by date
st.subheader("Average rain by date")
line_chart_data = filtered_data.groupby(['date', 'province'])['rain'].mean().reset_index()
line_chart = alt.Chart(line_chart_data).mark_line().encode(
    x='date:T',
    y=alt.Y('rain:Q', title='Average Rainfall (mm)'),
    color='province:N',  # Differentiate lines by province
    tooltip=['date:T', 'province:N', 'rain:Q']
).interactive()
st.altair_chart(line_chart, use_container_width=True)

# Map of rain in area
def interpolate_color(rain_amount, min_rain, max_rain):
    # Normalize rain amount between 0 and 1
    normalized_rain = (rain_amount - min_rain) / (max_rain - min_rain)
    red = 255 * (1 - normalized_rain)
    green = 255 * normalized_rain
    return [red, green, 0, 160]

# Aggregate rainfall by latitude and longitude
agg_data = filtered_data.groupby(['latitude', 'longitude'])['rain'].sum().reset_index()

# Get the min and max rain for normalization
min_rain = agg_data['rain'].min()
max_rain = agg_data['rain'].max()

# Apply color interpolation
agg_data['color'] = agg_data.apply(lambda row: interpolate_color(row['rain'], min_rain, max_rain), axis=1)

st.subheader("Map of rain in area")
view_state = pdk.ViewState(latitude=data['latitude'].mean(), longitude=data['longitude'].mean(), zoom=6)
layer = pdk.Layer(
    'ScatterplotLayer',
    data=agg_data,
    get_position='[longitude, latitude]',
    get_color='color',  # Use the color column for the color of each point
    get_radius='rain * 100',  # Adjust radius multiplier as needed
)
st.pydeck_chart(pdk.Deck(layers=[layer], initial_view_state=view_state))

# Overall Rainfall Summary
st.subheader("Overall Rainfall Summary")
total_rainfall = filtered_data['rain'].sum()
average_rainfall = filtered_data['rain'].mean()
min_rainfall = filtered_data['rain'].min()
max_rainfall = filtered_data['rain'].max()

# Summary by Province with Maximum and Minimum
province_rainfall_stats = filtered_data.groupby('province')['rain'].agg(['mean', 'sum']).reset_index()
max_rain_province = province_rainfall_stats.loc[province_rainfall_stats['mean'].idxmax()]
min_rain_province = province_rainfall_stats.loc[province_rainfall_stats['mean'].idxmin()]

st.code(f"""
Rainfall Analysis from {start_date.date()} to {end_date.date()}: \n
Total Rainfall: {total_rainfall} mm \n
Average Rainfall: {average_rainfall:.2f} mm \n
Minimum Rainfall: {min_rainfall} mm \n
Maximum Rainfall: {max_rainfall} mm
""", language=None)

st.code(f"""
Province with Maximum Average Rainfall: {max_rain_province['province']} ({max_rain_province['mean']:.2f} mm) \n
Province with Minimum Average Rainfall: {min_rain_province['province']} ({min_rain_province['mean']:.2f} mm)
""", language=None)

# Code of this assignment
st.subheader("Code of this assignment")
st.code(open(__file__).read())