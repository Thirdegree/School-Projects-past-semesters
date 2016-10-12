// Assignment #: 2
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30-5:45
//  Description: This class is a review of loops

import java.util.Scanner;

public class Assignment2 {
    public static void main(String[] args) {

        int sumEven = 0;
        //Biggest value possible for an int, 2^31 - 1
        int min = Integer.MAX_VALUE;
        int countPos = 0;
        int current;
        Scanner console = new Scanner(System.in);


        //needs to be run at least once, and 0s are included in calculations.
        do {
            //gets next Int from stdin
            current = console.nextInt();
            //if current is even
            if (current%2==0) {
                sumEven+=current;
            }
            //if current is smaller than min
            if (current<min) {
                min = current;
            }
            //if current is positive
            if (current>0) {
                countPos++;
            }
        } while (current!=0);

        System.out.printf("The minimum integer is %d\n"
                        + "The sum of even integers is %d\n"
                        + "The count of positive integers in the sequence is %d\n",
                         min, sumEven, countPos);
        
    }
}
