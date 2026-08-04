public class Medication  {
    protected String medication;
    protected String description;
    protected double price;
    private String id;
    private int qty;

    public Medication(String medication, String description, double price, String id) {
        this.medication = medication;
	this.description = description;
        this.price = price;
        this.id = id;
    }

    public void setQty(int qty){
	this.qty=qty;
    }

    public String getMedic() {
        return medication;
    }

    public String getDescription() {
	return description;
    }

    public double getPrice() {
	return price;
    }

    public String getID() {
        return id;
    }

    public int getQty(){
        return qty;
    }
}
