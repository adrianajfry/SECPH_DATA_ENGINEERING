public abstract class TennisShop{
	public String brand="";
	public double price=0.0;
	public int quantity=0;

	public TennisShop(){
		this.brand="";
		this.price=0.0;
		this.quantity=0;
	}

	public TennisShop(String b, double p, int q){
		this.brand=b;
		this.price=p;
		this.quantity=q;
	}

	public void setPrice(double p){price=p;}
	public String getBrand(){return brand;}
	public double getPrice(){return price;}
	public int getQuantity(){return quantity;}

	public abstract void display();
	public abstract double calcPrice();
}