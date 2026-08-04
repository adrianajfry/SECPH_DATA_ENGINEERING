public class Customer{
	private String CustName;
	private TennisShop[] itemList;
	private int numOfItem;
	private double totalPay;

	public Customer(String c){
		this.CustName=c;
		itemList = new TennisShop[10];
	}

	public String getName(){return CustName;}
	public double getTotalPay(){return totalPay;}
	public int getNumOfItem(){return numOfItem;}

	public void buy(TennisShop t){
		itemList[numOfItem]=t;
		System.out.println("Item " + (numOfItem+1));

		if(t instanceof Ball){
			System.out.println("TENNIS BALL");
		} else if(t instanceof Racket){
			System.out.println("TENNIS RACKET");
		}

		itemList[numOfItem].display();
		totalPay+=itemList[numOfItem].calcPrice();
		numOfItem++;
	}

	public String toString(){
		return "WELCOME Rafael Nadal\n\nList of Tennis Items Bought\n";
	}

	public void print(){
		System.out.printf("TOTAL: RM%.2f",totalPay);
		System.out.println();
	}

}