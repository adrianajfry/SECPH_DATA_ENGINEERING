import java.util.*;
import java.lang.*;

public class TestAccount{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int choice;
		double amount;
		Savings acc=new Savings("Ahmad");

		do{
			System.out.println("******** BANK ACCOUNT MENU ********");
			System.out.println();
			System.out.println("1. Savings Account Deposit");
			System.out.println("2. Savings Account Withdrawal");
			System.out.println("3. Display Report");
			System.out.println("4. Exit");
			System.out.println();
			System.out.print("Please enter your choice (1-4) : ");
			choice=in.nextInt();
			System.out.println();

			switch(choice){
				case 1:
				System.out.print("Enter amount to deposit: ");
				amount=in.nextDouble();
				System.out.println("Please insert your cash.");
				acc.deposit(amount);
				break;

				case 2:
				System.out.print("Enter amount to withdraw: ");
				amount=in.nextDouble();
				acc.withdraw(amount);
				break;

				case 3:
				acc.displayReport();
				break;

				case 4:
				System.exit(1);
				break;

				default:
				System.out.println("Invalid choice");
				break;

			}
			System.out.println();
		}while(choice!=4);
	}
}