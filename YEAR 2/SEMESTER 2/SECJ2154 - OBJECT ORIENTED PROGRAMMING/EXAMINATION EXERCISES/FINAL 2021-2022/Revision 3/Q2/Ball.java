class Ball extends TennisShop implements DiscConsiderable{
	private int numOfCan;

	public Ball(){
		super("",0.0,0);
		numOfCan=0;
	}

	public Ball(String b, double p, int q, int n){
		super(b,p,q);
		this.numOfCan=n;
	}

	public double calcDisc(){
		return price-(price*RATE);
	}

	public void display(){
		System.out.println("Brand   : " + brand);
		System.out.printf("Price   : RM%.2f for ",price);
		System.out.println(numOfCan + " can case");
		System.out.printf("Discount: %.1f",(RATE*100));
		System.out.println("%");
		System.out.println("Quantity: " + quantity);
		System.out.printf("SubTotal: RM %.2f",calcPrice());
		System.out.println();
		System.out.println();

	}

	public double calcPrice(){
		return calcDisc()*quantity;
	}
}