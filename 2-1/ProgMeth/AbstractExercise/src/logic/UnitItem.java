package logic;

public class UnitItem extends Item {
	private int amount;
	
	public UnitItem(String name, double unitPrice, int amount) {
		setName(name);
		setUnitPrice(unitPrice);
		setAmount(amount);
	}
	
	public double cost() {
		return getUnitPrice() * getAmount();
	}
	
	public String toString() {
		return "UnitItem : " + name + " " + amount + " " + unitPrice + " " + cost();
	}

	public int getAmount() {
		return amount;
	}

	public void setAmount(int amount) {
		this.amount = amount;
	}
}
