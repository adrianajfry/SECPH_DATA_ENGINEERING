// Nurul Adriana Binti Kamal Jefri
// A23CS0258

// Question 1
public class Main {
    public static void main(String[] args) {
        Employee e1 = new Employee();
        e1.setEmpNum(101);
        e1.setEmpName("Ali");
        System.out.println("Employee Number: " + e1.getEmpNum());
        System.out.println("Employee Name: " + e1.getEmpName());
    }
}

class Employee {
    private int empNum;
    private String empName;
    
    // Setter methods
    public void setEmpNum(int empNum) {
        this.empNum = empNum;
    }
    
    public void setEmpName(String empName) {
        this.empName = empName;
    }
    
    // Getter methods
    public int getEmpNum() {
        return empNum;
    }
    
    public String getEmpName() {
        return empName;
    }
}


// Question 2
class Car {
    // Private instance variables
    private String brand;
    private int year;

    // Setter for brand
    public void setBrand(String brand) {
        this.brand = brand;
    }

    // Getter for year
    public int getYear() {
        return year;
    }
}


// Question 3
public class Main {
    public static void main(String[] args) {
        Book b1 = new Book("Java 101", "John Doe");
        b1.display();
    }
}

class Book {
    private String title;
    private String author;

    // Parameterized constructor
    public Book(String title, String author) {
        this.title = title;
        this.author = author;
    }

    public void display() {
        System.out.println("Title: " + title);
        System.out.println("Author: " + author);
    }
}


// Question 4
class Student {
    private String name;
    private int age;

    // Setter for name
    public void setName(String name) {
        this.name = name;
    }

    // Getter for age
    public int getAge() {
        return age;
    }
}


// Question 5
class Message {
    // Method without parameters
    public void display() {
        System.out.println("Hello!");
    }

    // Overloaded method with String parameter
    public void display(String msg) {
        System.out.println("Message: " + msg);
    }
}


// Question 6
class User {
    // Static counter variable
    private static int userCount = 0;

    public User() {
        // Increment counter each time a User is created
        userCount++;
    }

    public static int getUserCount() {
        // Return the current count
        return userCount;
    }
}

public class Main {
    public static void main(String[] args) {
        new User();
        new User();
        System.out.println("Total Users: " + User.getUserCount()); // Output: Total Users: 2
    }
}


// Question 7
class Employee {
    // Private salary field
    private double salary;

    // Setter method for salary
    public void setSalary(double salary) {
        this.salary = salary;
    }

    // Getter method for salary
    public double getSalary() {
        return salary;
    }
}

public class Main {
    public static void main(String[] args) {
        Employee e = new Employee();
        e.setSalary(5000);
        System.out.println("Salary: " + e.getSalary());  // Output: Salary: 5000.0
    }
}