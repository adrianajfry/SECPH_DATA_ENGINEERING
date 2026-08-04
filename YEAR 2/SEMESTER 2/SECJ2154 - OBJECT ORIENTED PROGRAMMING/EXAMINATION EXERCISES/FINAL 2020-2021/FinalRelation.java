//Exam

import java.util.*;

class Subject {
	private String name;

	public Subject (String name){
		this.name = name;
	}

	public String getName() {
		return name;
	}
}

class Student {
	private Vector <Subject> sList;

	public Student(){
		sList = new Vector<Subject>();
	}

	public void addSubject(Subject s){
		if (sList.size()<=3){
			System.out.println("Add " + Subject.getName() + " to the list");
			sList.addElement(Subject.getName());
		}
		else
			System.out.println("the list is full");
	}
	public void removeSubject(){
		if(!isEmpty()){
			System.out.println("Remove " + Subject.getName() + " from the list");
			sList.removeElement(Subject.getName());
		}
		else
			System.out.println("Ths list is empty");
	}

	public void printList(){
		System.out.print("Subjects in the list: ");
		for (Subject s : sList)
			System.out.print(s + " ");
			System.out.println();
		}
}

public class FinalRelation {
	public static void main (String [] a){
		Student s = new Student();
		Subject [] subj = { new Subject ("Bio"),
							new Subject ("chem"),
							new Subject ("Phy"),
							new Subject ("math"),
							new Subject ("eng")};
		s.removeSubject();
		s.addSubject(subj[3]);
		s.addSubject(subj[0]);
		s.addSubject(subj[1]);
		s.addSubject(subj[2]);
		s.printList();
		s.removeSubject(subj[3]);
}