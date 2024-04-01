package logic;

public class WeightItem extends Item{
	private double weight;
	
	public WeightItem(String name, double unitPrice) {
		setName(name);
		setUnitPrice(unitPrice);
		setWeight(scale());
	}
	
	public double cost() {
		return getUnitPrice() * getWeight();
	}
	
	public double scale() {
		return Math.random() * (4.00 - 0.01) + 0.01;
	}
	
	public String toString() {
		return "UnitItem : " + name + " " + weight + " " + unitPrice + " " + cost();
	}

	public double getWeight() {
		return weight;
	}

	public void setWeight(double weight) {
		this.weight = weight;
	}
	
	
}
