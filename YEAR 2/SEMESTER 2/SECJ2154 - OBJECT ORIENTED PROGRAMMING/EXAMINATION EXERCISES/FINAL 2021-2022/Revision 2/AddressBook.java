public class AddressBook{
	private Person[] entry;
	private int count;
	public BusinessAssociate ba;
	public PersonalFriend pf;

	public AddressBook(){
		count=0;
	}

	public AddressBook(int c){
		entry = new Person[c];
	}

	public void addPerson(Person p){
		entry[count]=p;
		count++;
	}

	public void displayAddressBook(){
		/*System.out.println("Name: " + entry[0].getName());
		System.out.println("Phone: " + entry[0].getPhone());
		System.out.println("Address: " + entry[0].address.getFullAddress());
		System.out.println();
		ba.dispBusinessAssociate();
		System.out.println();
        pf.dispPersonalFriend();*/
		for(int i=0;i<count;i++){
			if(entry[i] instanceof PersonalFriend){
				//pf = ((PersonalFriend) entry[i]);
				//pf.dispPersonalFriend();
				((PersonalFriend) entry[i]).dispPersonalFriend();
		    } else if(entry[i] instanceof BusinessAssociate){
				//ba = ((BusinessAssociate) entry[i]);
				//ba.dispBusinessAssociate();
				((BusinessAssociate) entry[i]).dispBusinessAssociate();
		    } else{
				System.out.println("Name: " + entry[i].getName());
				System.out.println("Phone: " + entry[i].getPhone());
		        System.out.println("Address: " + entry[i].address.getFullAddress());
		        System.out.println();
			}
		}
	}
}