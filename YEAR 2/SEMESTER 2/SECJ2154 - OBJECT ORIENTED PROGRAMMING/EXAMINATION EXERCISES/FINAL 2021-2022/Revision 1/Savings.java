class Savings extends Account implements Profit{
	private String accName;

	public Savings(String a){
		super("001",2000.00);
		accName=a;
	}

	public double calcHibah(){
		return (balance * HIBAH_RATE);
	}

	public void displayReport(){
		System.out.printf("Montly Hibah Earned: RM%.2f",calcHibah());
		System.out.println();
		System.out.printf("Ending Balance: RM%.2f",(calcHibah()+balance));
		System.out.println();
	}

}