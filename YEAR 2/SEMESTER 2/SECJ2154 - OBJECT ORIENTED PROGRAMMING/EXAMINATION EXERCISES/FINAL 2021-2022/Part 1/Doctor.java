public class Doctor  {
    private String name;
    private double consultationFee;
    private String specialization;
    private String roomNum;
    Availability time;

    public Doctor(String name, double consultationFee, String specialization, String roomNum,  String t) {
        this.name=name;
        this.consultationFee = consultationFee;
        this.specialization = specialization;
        this.roomNum = roomNum;
        time = Enum.valueOf(Availability.class, t);
    }

    public double getConsultationFee() {
        return consultationFee;
    }

    public String getSpecial() {
        return specialization;
    }

    public String getroomNum() {
        return roomNum;
    }

    public void displayDoctor() {
        System.out.println("Name :" + name);
	    System.out.println("Specialized in: " + specialization);
        System.out.println("Room Number: " + roomNum);

// TASK 2(i): Modify if..else statement below to display starthour and endhour for every session. [6 marks]

        if ((time.getSession().equals("Morning"))) {

            System.out.println("Time available from " + time.getStartTime() + " to " + time.getEndTime());

        } else if ((time.getSession().equals("Afternoon"))) {

            System.out.println("Time available from " + time.getStartTime() + " to " + time.getEndTime());

        } else if ((time.getSession().equals("Night"))) {

            System.out.println("Time available from " + time.getStartTime() + " to " + time.getEndTime());

        }

    }
}
