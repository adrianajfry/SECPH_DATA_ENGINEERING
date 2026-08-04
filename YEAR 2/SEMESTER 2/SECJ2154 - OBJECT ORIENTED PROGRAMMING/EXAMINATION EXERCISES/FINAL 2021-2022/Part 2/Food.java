public class Food extends Product{
	private double quantity;

	public Food(String d,double p,double q){
		super(d,p);
		this.quantity=q;
	}

	public double calcPrice(){
		return getPrice()*quantity;
	}

	public String dispInfo(){
		return "Description: " + getDescription() +
		       "\nPrice: RM" + String.format("%.2f",getPrice()) + " per kg" +
		       "\nQuantity: " + quantity +
		       "\nSubtotal Price: RM" + String.format("%.2f",calcPrice());
	}
}