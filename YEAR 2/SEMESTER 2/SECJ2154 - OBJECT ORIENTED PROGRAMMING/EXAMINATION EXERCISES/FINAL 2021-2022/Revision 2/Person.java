public class Person{
	private String name;
	private String phone;
	public Address address;

	public Person(){
		name="";
		phone="";
	}

	public Person(String n, String p, Address a){
		name=n;
		phone=p;
		address=a;
	}

	public void setName(String n){name=n;}
	public void setPhone(String p){phone=p;}
	public String getName(){return name;}
	public String getPhone(){return phone;}

}