class BusinessAssociate extends Person{
	private String jobtitle;
	private String companyName;

	public BusinessAssociate(){
		jobtitle="";
		companyName="";
	}

	public BusinessAssociate(String n, String p,Address a,String j, String c){
		super(n,p,a);
		this.jobtitle=j;
		this.companyName=c;
	}

	public String getJobTitle(){return jobtitle;}
	public String getCompanyName(){return companyName;}

	public void dispBusinessAssociate(){
		System.out.println("Name: " + getName());
		System.out.println("Phone: " + getPhone());
		System.out.println("Job Title: " + getJobTitle());
		System.out.println("Company: " + getCompanyName());
		System.out.println("Address: " + address.getFullAddress());
		System.out.println();
	}
}