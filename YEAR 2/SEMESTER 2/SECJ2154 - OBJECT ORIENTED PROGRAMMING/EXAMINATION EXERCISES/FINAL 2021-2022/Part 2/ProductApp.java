import java.util.*;

public class ProductApp{
	public static void displayMenu(){
		System.out.println("========== Menu ==========");
		System.out.println("[1] Add Customer");
		System.out.println("[2] Purchase Vehicle");
		System.out.println("[3] Purchase Food");
		System.out.println("[4] Display Shopping List");
		System.out.println("[5] Exit");
		System.out.println("==========================");
		System.out.print("\nSelect task: ");
	}

	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int choice,numCust=0;
		double price,quantity;
		String name,des,type;
		Vector<Customer> cList = new Vector<Customer>();
		Customer c;



		do{
			displayMenu();
			choice=in.nextInt();
			in.nextLine();
			System.out.println();

			try{
				if(choice<1 || choice>5){
					throw new Exception("Invalid Input!!");
				}
			}
			catch(Exception e){
					System.out.println(e);
					System.out.println();
					break;
			}

			switch(choice){
				case 1: System.out.println("<<< Add Customer >>>");
				        System.out.print("Name: ");
				        name=in.nextLine();
				        c=new Customer(name);
				        cList.addElement(c);
				        numCust++;
				        System.out.println();
				        break;

				case 2: try{
					        if(numCust==0){
								throw new IllegalArgumentException("There is no customer. Please start by entering the customer's name.");
							}
							System.out.println("<<< Purchase Vehicle >>>");
							System.out.print("Description: ");
							des=in.nextLine();
							System.out.print("Type: ");
							type=in.next();
							System.out.print("Price (in RM): ");
							price=in.nextDouble();

							Product p = new Vehicle(des,price,type);
							cList.get(0).purchase(p);

							System.out.println();
					    }
					    catch(IllegalArgumentException e){
							System.out.println(e.getMessage());
							System.out.println();
						}
				        break;

				case 3:try{
					        if(numCust==0){
								throw new IllegalArgumentException("There is no customer. Please start by entering the customer's name.");
							}
							System.out.println("<<< Purchase Food >>>");
							System.out.print("Description: ");
							des=in.nextLine();
							System.out.print("Price (in RM): ");
							price=in.nextDouble();
							System.out.print("Quantity (in kg): ");
							quantity=in.nextDouble();

							Product p = new Food(des,price,quantity);
							cList.get(0).purchase(p);

							System.out.println();
					    }
					    catch(IllegalArgumentException e){
							System.out.println(e.getMessage());
							System.out.println();
						}
				        break;

				case 4:try{
					        if(numCust==0){
								throw new IllegalArgumentException("There is no customer. Please start by entering the customer's name.");
							}else if(cList.get(0).calcProductPurchased()==0){
								throw new ArithmeticException("No products were purchased!!");
							}
							System.out.println(cList.get(0).toString());
							System.out.println();
							cList.get(0).show();
							System.out.println();
					    }
					    catch(IllegalArgumentException e){
							System.out.println(e.getMessage());
							System.out.println();
						}
						catch(ArithmeticException e){
							System.out.println(e.getMessage());
							System.out.println();
						}
				        break;

				case 5: System.out.println();
				        System.out.println("Thank you! :)");
				        break;
			}

		}while(choice!=5);
	}
}