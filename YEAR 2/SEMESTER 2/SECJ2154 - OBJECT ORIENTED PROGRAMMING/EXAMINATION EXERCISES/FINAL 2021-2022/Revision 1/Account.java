abstract class Account{
	protected String accNo;
	protected double balance;

	public Account(){
		accNo = "";
		balance = 0.0;
	}

	public Account(String a, double b){
		this.accNo = a;
		this.balance = b;
	}

	public abstract void displayReport();

	public void deposit(double amount){
		balance+=amount;

		System.out.println("Deposit accepted");
		System.out.printf("Your current balance is RM%.2f",balance);
		System.out.println();
	}

	public void withdraw(double request_amount){
		if(request_amount<0){
			System.out.println("Invalid amount");
		}else if((balance-request_amount)<0){
			System.out.println("Insufficient balance");
		}else if(balance==0){
			System.out.println("Insufficient balance");
		}else {
			balance-=request_amount;
			System.out.println("Please take your cash.");
		    System.out.printf("Your current balance is RM%.2f",balance);
		    System.out.println();
		}
	}
}