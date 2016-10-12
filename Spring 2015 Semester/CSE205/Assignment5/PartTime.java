// Assignment #: 5
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30-5:45
//  Description: Based on Employee

import java.text.DecimalFormat;

public class PartTime extends Employee {
    private double rate;
    private int hoursWorked;

    //constructor +2
    public PartTime(String firstName, String lastName, String employeeId, double rate, int hoursWorked) {
        super(firstName, lastName, employeeId);
        this.rate = rate;
        this.hoursWorked = hoursWorked;
    }

    //implemented computePay
    public void computePay() {
        pay = rate * hoursWorked;
    }

    //added onto toString
    public String toString() {

        DecimalFormat money = new DecimalFormat("$#,##0.00");
        String extra = "\nPart Time Employee:" 
                    + super.toString() 
                    + String.format("Rate:\t\t\t%s\n"
                                    +"Hours:\t\t\t%s\n",
                                    money.format(rate), hoursWorked);
        return extra;
    }
}
