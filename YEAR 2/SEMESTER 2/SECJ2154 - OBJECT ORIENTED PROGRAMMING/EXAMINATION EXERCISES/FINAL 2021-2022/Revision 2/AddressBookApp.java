public class AddressBookApp{
	public static void main(String[] args){
		AddressBook book1 = new AddressBook(10);
		Address ad1 = new Address("No 2 Jalan Mawar","Skudai","Johor Bahru");
		Address ad2 = new Address("Block 1-7","Cheras","Kuala Lumpur");
		Address ad3 = new Address("202-2 Jalan Bendahara","Muar","Johor");

		Person newfriend1 = new Person("Ms. X","555-1212", ad1);
		book1.addPerson(newfriend1);

		BusinessAssociate b1;
		b1 = new BusinessAssociate("Mr. Yeo","019-2342",ad2,"General Manager","Motorola");
		book1.addPerson(b1);

		PersonalFriend f1 = new PersonalFriend("Mrs. Zyda","012-8278",ad3,"My school mate");
		book1.addPerson(f1);

		book1.displayAddressBook();
	}
}