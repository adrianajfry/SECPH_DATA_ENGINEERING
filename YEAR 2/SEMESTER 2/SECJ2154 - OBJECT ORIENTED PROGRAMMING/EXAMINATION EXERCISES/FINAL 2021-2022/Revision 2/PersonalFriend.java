class PersonalFriend extends Person{
	private String message;

	public PersonalFriend(){
		message="";
	}

	public PersonalFriend(String n, String p, Address a, String m){
		super(n,p,a);
		this.message=m;
	}

	public String getMessage(){return message;}

	public void dispPersonalFriend(){
		System.out.println("Name: " + getName());
		System.out.println("Phone: " + getPhone());
		System.out.println("Address: " + address.getFullAddress());
		System.out.println("Message: " + getMessage());
		System.out.println();
	}
}