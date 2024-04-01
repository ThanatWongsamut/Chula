#ifndef __STUDENT_H_
#define __STUDENT_H_

template<typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data) {
    std::sort(data.begin(), data.end());
    int i = 0;
    int j = 0;

    int s = mSize + data.size();
    T *arr = new T[s];

    auto d = data.begin();
    while (true) {
        if (d != data.end() && d->first == j) arr[i++] = d++->second;
        if (j >= mSize) break;
        arr[i++] = mData[j++];
    }

    delete[] mData;
    mData = arr;
    mSize = s;
    mCap = s;
}

#endif