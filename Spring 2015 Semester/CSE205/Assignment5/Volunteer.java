// Assignment #: 5
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30-5:45
//  Description: Based on Employee

public class Volunteer extends Employee {
    public Volunteer(String firstName, String lastName, String employeeId) {
        super(firstName, lastName, employeeId);
    }

    //implemented computePay
    public void computePay() {
        pay = 0.0;
    }

    //added on to toString
    public String toString() {
        String extra = "\nVolunteer:" + super.toString();
        return extra;
    }
}