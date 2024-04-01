package logic;

abstract class Item {
	protected String name;
	protected double unitPrice;
	
	
	public Item() {}
	
	
	abstract double cost();


	public String getName() {
		return name;
	}


	public void setName(String name) {
		this.name = name;
	}


	public double getUnitPrice() {
		return unitPrice;
	}


	public void setUnitPrice(double unitPrice) {
		this.unitPrice = unitPrice;
	}
	
}
