// Assignment #: 5
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30-5:45
//  Description: Based on Employee

import java.text.DecimalFormat;

public class FullTime extends Employee {
    private double rate;
    private double bonus;

    //consturctor +2
    public FullTime(String firstName, String lastName, String employeeId, double rate, double bonus) {
        super(firstName, lastName, employeeId);
        this.rate = rate;
        this.bonus = bonus;
    }

    //implemented computePay
    public void computePay() {
        pay = rate + bonus;
    }

    //added onto toString
    public String toString() {

        DecimalFormat money = new DecimalFormat("$#,##0.00");
        String extra = "\nFull Time Employee:" 
                    + super.toString() 
                    + String.format("Rate:\t\t\t%s\n"
                                    +"Bonus:\t\t\t%s\n",
                                    money.format(rate), money.format(bonus));
        return extra;
    }
}
