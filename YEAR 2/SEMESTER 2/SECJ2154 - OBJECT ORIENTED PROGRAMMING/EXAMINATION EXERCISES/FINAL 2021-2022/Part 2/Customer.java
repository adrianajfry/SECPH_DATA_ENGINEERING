import java.util.*;

public class Customer{
	private String name;
	private double totalPrice;
	private Vector<Product> productList;

	public Customer(String n){
		this.name=n;
		productList=new Vector<Product>();
	}

	public void purchase(Product p){
		productList.addElement(p);
		totalPrice+=p.calcPrice();
	}

	public String toString(){
		return "<<< " + name + "'s shopping list >>>";
	}

	public void show(){
		System.out.println("Number of products purchased: " + calcProductPurchased());
		System.out.println();
		for(int i=0;i<productList.size();i++){
			System.out.println("Product " + (i+1));
			System.out.println((productList.get(i)).dispInfo());
			System.out.println();
		}
		System.out.printf("TOTAL PRICE: RM%.2f",totalPrice);
		System.out.println();
	}

	public int calcProductPurchased(){
		return productList.size();
	}
}