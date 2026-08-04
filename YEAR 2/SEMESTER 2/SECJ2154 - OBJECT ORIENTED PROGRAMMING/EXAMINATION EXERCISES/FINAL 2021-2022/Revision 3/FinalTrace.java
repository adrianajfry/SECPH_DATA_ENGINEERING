import java.util.*;

public class FinalTrace{
	public static void main(String[] ar){
		ArrayList<Integer> list = new ArrayList <Integer>(); // 1.Int=>Integer
		list.add(100);
		list.add(200);
		int num = list.get(1);
		System.out.println("Number at index 1 in your arraylist: " + num);

		list.set(1,500); //2. list.set(2,500)=>list.set(1,500)
		System.out.print("The current numbers in your arraylist: ");
		for(int i=0;i<list.size();i++) // 3. list.length=>list.size()
		   System.out.print(list.get(i) + " ");
		System.out.println("\n----------------------");

		int [] arr = new int[3];
		getValues(arr);
		System.out.print("The numbers of array that you already entered: ");
		for(int i=0;i<arr.length;i++) // 4. arr.size()=>arr.length
		   System.out.print(arr[i] + " ");
		System.out.println("\n----------------------");

		classA obj1 = new classA();
		classA obj2 = new classC(2500);// 5. 2500
		classC obj3 = new classC();
		System.out.print(obj2.toString());

		System.out.println("----------------------");
		try{
			if(num == 200)
				throw new FinalException(); // 6. throws=>throw
		}catch(FinalException fe){
			System.out.println(fe.getMessage());
	    }
	}

	public static void getValues(int [] a){
		Scanner input = new Scanner(System.in);
		System.out.println("Please enter the numbers for " + a.length + " elements of array..");

		for(int i=0;i<a.length;i++){ // 7. a.size()=>a.length
			System.out.print("Enter number " + (i+1) + ": ");
			a[i] = input.nextInt();
		}
	}
}

class classA{
	private classB objB;
	private int varA;

	public classA(int i){
		objB = new classB("ObjB");
		this.varA = i;
	}

	public classA(){
		System.out.println("You are creating object for Class A");
	}

	public classA(String arg){ // 8. public String classA=>public classA
		System.out.println("Wish you: " + arg);
	}

	public int getVarA(){
		return varA;
	}

	public String toString(){
		return "Name of object: " + objB.getVarB() + "\nYou are creating object for " + getVarA() + "\n"; // 9. getVarB()=>objB.getVarB()
	}
}

class classB{
	String varB;

	classB(String n){
		this.varB = n;
	}

	public String getVarB(){
		return varB;
	}
}

class classC extends classA{
	classC(){
		super("Good Luck!!"); // 10. this=>super
	}

	classC(int a){
		super(a); // 11. this=>super
	}
}

class FinalException extends Exception{
	private String msg;

	FinalException(){
		msg = new String("This is our Final exception.");
	}

	public String getMessage(){
		return msg;
	}
}

