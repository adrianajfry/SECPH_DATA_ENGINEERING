// Nurul Adriana Binti Kamal Jefri
// A23CS0258

import java.util.*;

public class ArrayLab {

        public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
    
        // Part A: Spot the Errors
        System.out.println("== Part A ==");
    
        // Question 1: Fix broken array initialization
        double gpa[] = new double[4]; 
        System.out.println("Part A, Question 1: no output, fixed.");
    
        // Question 2: Fix shorthand array assignment
        int[] points = {90, 85, 88};
        System.out.println("Part A, Question 2: no output, fixed.");
    
        // Question 3: Fix variable-length argument method (correct version below main)
        System.out.println("Part A, Question 3: no output, fixed.");
    
        // Part B: Write Short Array Declarations
        System.out.println("\n== Part B ==");
    
        // Question 1: 2D array matrix
        int[][] matrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        System.out.println("Part B, Question 1: done.");
    
        // Question 2: ArrayList of grades
        ArrayList<Double> grades = new ArrayList<>(Arrays.asList(3.5, 4.0, 2.8)); // ✅ Initialized
        System.out.println("Part B, Question 2: done.");
    
        // Question 3: Anonymous array to print average
        printAverage(new int[]{10, 20, 30, 40}); // ✅ Called with anonymous array
    
        // 1D array for student scores
        int[] scores = new int[5];
        for (int i = 0; i < scores.length; i++) {
            System.out.print("Enter score " + (i + 1) + ": ");
            scores[i] = input.nextInt();
        }
    
        // Part C: Create & Use Methods
        System.out.println("\n== Part C ==");
    
        // Question 1: Find highest score
        int highest = findHighestScore(scores);
        System.out.println("Part C, Question 1: Highest Score = " + highest);
    
        // 2D array for marks of 3 students and 3 subjects
        int[][] marks = {
            {85, 78, 90},
            {88, 92, 79},
            {75, 80, 85}
        };
    
        // ArrayList of subjects
        ArrayList<String> subjects = new ArrayList<>();
        subjects.add("Math");
        subjects.add("Science");
        subjects.add("English");
    
        // Array of Student objects
        Student[] students = new Student[3];
        students[0] = new Student("Ali", 20);
        students[1] = new Student("Siti", 21);
        students[2] = new Student("Raj", 19);
    
        // Question 2: Print student info using method
        printStudentInfo(students);
    
        // Question 3: Sum subject marks
        int totalMarks = sumSubjectMarks(marks);
        System.out.println("Part C, Question 3: Total Marks = " + totalMarks);
    
        input.close();
    }


    // Part A, Question 3: Fixed method signature for varargs
    public static void printTotal(String title, int... values) {
        int sum = 0;
        for (int v : values) {
            sum += v;
        }
        System.out.println("Part A, Question 3: " + title + " total = " + sum);
    }

    // Part B, Question 3: Print average from anonymous array
    public static void printAverage(int[] values) {
        double sum = 0;
        for (int v : values) {
            sum += v;
        }
        double avg = sum / values.length;
        System.out.println("Part B, Question 3: Average = " + avg);
    }

    // Part C, Question 1: Find highest score
    public static int findHighestScore(int[] scores) {
        int max = scores[0];
        for (int s : scores) {
            if (s > max) {
                max = s;
            }
        }
        return max;
    }

    // Part C, Question 2: Print student info
    public static void printStudentInfo(Student[] arr) {
        System.out.println("Part C, Question 2: Student Info");
        for (Student s : arr) {
            System.out.println("Student: " + s.getName() + ", Age: " + s.getAge());
        }
    }

    // Part C, Question 3: Sum all marks in 2D array
    public static int sumSubjectMarks(int[][] marks) {
        int sum = 0;
        for (int[] row : marks) {
            for (int mark : row) {
                sum += mark;
            }
        }
        return sum;
    }
}

// Student class
class Student {
    private String name;
    private int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() { return name; }
    public int getAge() { return age; }
}
