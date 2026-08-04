public class FinalQ2{
	public static void main(String[] args){
		TennisShop p1 = new Racket("Naiky",0,3,2);
		TennisShop p2 = new Ball("Wilson Anne",225.00,3,24);
		TennisShop p3 = new Ball("Penn",240.00,5,18);
		TennisShop p4 = new Racket("Dunlop",0,4,4);

		Customer c = new Customer("Rafael Nadal");
		System.out.println(c.toString());
		c.buy(p1);
		c.buy(p2);
		c.buy(p3);
		c.buy(p4);
		c.print();
	}
}