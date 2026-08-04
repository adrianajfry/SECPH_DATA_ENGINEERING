enum Availability {

// TASK 1(i): enum constant values and fields come here [6 marks]
// Complete the enum declaration in Availability class using the data stated in Table 1
    M("Morning",8.00,12.00),
    A("Afternoon",13.00,18.00),
    N("Night",19.00,23.00);


    private String session;
    private double starthour;
    private double endhour;

    Availability(String s, double start, double end) {
        session = s;
        starthour = start;
        endhour = end;
    }

    public String getSession() {
        return session;
    }

    public double getStartTime() {
        return starthour;
    }

    public double getEndTime() {
        return endhour;
    }
}
