class Racket extends TennisShop{
	private int racketType;

	public Racket(){
		super("",0.0,0);
		racketType=0;
	}
	public Racket(String b, double p, int q, int r){
		super(b,p,q);
		this.racketType=r;
	}


	public void display(){
		System.out.println("Brand   : " + brand);

		if (racketType==1){
			this.price=80.00;
			System.out.println("Type    : Junior Tennis Racket" );
		} else if (racketType==2){
			this.price=110.00;
			System.out.println("Type    : Beginners Tennis Racket" );
		} else if (racketType==3){
			this.price=235.00;
			System.out.println("Type    : Advanced Tennis Racket" );
		} else if (racketType==4){
			this.price=185.00;
			System.out.println("Type    : All Tennis Racket" );
		}

		System.out.printf("Price   : RM%.2f",price);
		System.out.println();
		System.out.println("No Discount!");
		System.out.println("Quantity: " + quantity);
		System.out.printf("SubTotal: RM %.2f",calcPrice());
		System.out.println();
		System.out.println();

	}

	public double calcPrice(){
		return price*quantity;
	}
}