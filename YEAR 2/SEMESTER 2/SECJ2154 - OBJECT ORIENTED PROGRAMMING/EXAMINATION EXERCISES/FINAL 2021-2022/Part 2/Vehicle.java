public class Vehicle extends Product implements Taxable{
	private String type;

	public Vehicle(String d,double p,String t){
		super(d,p);
		this.type=t;
	}

	public double calcTax(){
		return getPrice()*TaxRate;
	}

	public double calcPrice(){
		return getPrice()+calcTax();
	}

	public String dispInfo(){
		return "Description: " + getDescription() +
		       "\nType: " + type +
		       "\nPrice before tax: RM" + String.format("%.2f",getPrice()) +
		       "\nPrice after tax: RM " + String.format("%.2f",calcPrice()) +
		       "\nThe tax levied: RM" + String.format("%.2f",calcTax());
	}
}