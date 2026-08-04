import java.util.ArrayList;

public class Patient  {
    private String name;
    private String phoneNum;
    private String address;
    private int age;
    private Consultation cons;
    private Doctor doctor;
    ArrayList<Medication> medicItem = new ArrayList<Medication>();
    public double OLD_CITIZEN=0.10;

    Patient(String name, String phoneNum, String address, int age, Consultation app) {
        this.name=name;
        this.phoneNum=phoneNum;
        this.address = address;
        this.age = age;
        cons = app;

    }
	public String getName() {
        return name;
    }

	public String getPhoneNumber() {
        return phoneNum;
    }

	public String getAddress() {
        return address;
    }
 	public int getAge() {
         return age;
    }

// TASK 3(i): Define buyMedication method to establish association relationship between class Patient and Medication.  [4 marks]
// TASK 3(ii): Medication objects passed to this method can be added to the ArrayList.
    public void buyMedication(Medication m){
		medicItem.add(m);
	}

    public void consultSet(Consultation app) {
        cons = app;
    }

    public void meetDr(Doctor d) {
        doctor = d;
    }


    public void consultDisplay() {

        doctor.displayDoctor();

// TASK 4(i): Modify the codes in method consultDisplay to display consultation date and time. [2 marks]

        System.out.println("\nConsultation date: " + cons.getDate());
        System.out.printf("Consultation time : %.2f", cons.getTime());
    }

    public void display() {
        double totalprice=0;
        double payableCost = 0;
        System.out.println("Name :" + name);
	System.out.println("Phone Number: " + phoneNum);
        System.out.println("Address: " + address);
        System.out.println("List of medication :");
        System.out.println();

// TASK 5(i): Modify the following codes to display the medication list, calculate and display the medicine total price, consultation fee and total cost (medicine  + consultation fee) [10 marks]

	 for (int i = 0; i < medicItem.size(); i++) {
            System.out.println("[" + (i + 1) + "]Item: " + (medicItem.get(i)).getMedic() + "\n Description :"+ (medicItem.get(i)).getDescription());
            System.out.printf("Price : Rm%.2f\n", (medicItem.get(i)).getPrice());
            totalprice += (medicItem.get(i)).getPrice()* (medicItem.get(i)).getQty();
            System.out.println();
          }

	  payableCost=totalprice + doctor.getConsultationFee();
          System.out.printf("MEDICINE         : RM%.2f\n",totalprice );
          System.out.printf("CONSULTATION FEE : RM%.2f\n",doctor.getConsultationFee());
          System.out.printf("TOTAL            : RM%.2f\n",payableCost );

		if (age>=65)
		{
			double totalDiscount=payableCost*OLD_CITIZEN;
         	        payableCost=payableCost-totalDiscount;
			System.out.printf("TOTAL AFTER OLD CITIZEN DISCOUNT : RM%.2f\n",payableCost );
	        }




     }
}
