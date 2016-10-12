// Assignment #: 5
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30-5:45
//  Description: abstract class for Volunteer, PartTime, FullTime

import java.text.DecimalFormat;

public abstract class Employee {
    //protected variables
    protected String firstName;
    protected String lastName;
    protected String employeeId;
    protected double pay;

    //constructor
    public Employee(String firstName, String lastName, String employeeId) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.employeeId = employeeId;
        pay = 0.0;
    }

    //ID getter
    public String getEmployeeId() {
        return employeeId;
    }

    //abstract to compute pay for Volunteer, PartTime, FullTime class
    public abstract void computePay();

    //base toString
    public String toString() {
        String money = "$#,##0.00";
        DecimalFormat cash = new DecimalFormat(money);
        String str = String.format("\nFirst name:\t\t%s\n"
                            +"Last name:\t\t%s\n"
                            +"Employee ID:\t\t%s\n"
                            +"Pay:\t\t\t%s\n", 
                            firstName, lastName, employeeId, cash.format(pay));

        return str;
    }
}