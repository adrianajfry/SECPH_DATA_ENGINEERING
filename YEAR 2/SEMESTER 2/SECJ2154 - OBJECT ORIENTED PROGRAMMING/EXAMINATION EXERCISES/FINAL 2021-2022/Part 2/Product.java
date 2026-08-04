abstract class Product{
	private String description;
	private double price;

	public Product(){}
	public Product(String d, double p){
		this.description=d;
		this.price=p;
	}

	public String getDescription(){return description;}
	public double getPrice(){return price;}

	public abstract double calcPrice();
	public abstract String dispInfo();
}