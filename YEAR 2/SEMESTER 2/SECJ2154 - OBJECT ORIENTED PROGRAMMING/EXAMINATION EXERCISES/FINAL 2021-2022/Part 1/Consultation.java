public class Consultation {
    private String date;
    private double time;

    Consultation(String date, double time){
        this.date=date;
        this.time=time;
    }

    public String getDate(){
        return date;
    }

    public double getTime(){
        return time;
    }
}
