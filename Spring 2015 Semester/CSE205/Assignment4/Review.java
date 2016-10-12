// Assignment #: 4
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30-5:45
//  Description: This class is used by Book for reviews of the Book.

import java.text.DecimalFormat;
public class Review {
    private int numberOfReviews;
    private double sumOfRatings;
    private double average;

    //standard constructor
    public Review() {
        numberOfReviews = 0;
        sumOfRatings = 0.0;
        average = 0.0;
        
    }

    //updates numberOfReviews and sumOfRatings, and recalculates average
    public void updateRating(double rating) {
        numberOfReviews++;
        sumOfRatings += rating;
        average = sumOfRatings/numberOfReviews;
    }

    //custom toString used in Book class
    public String toString() {
        String pattern = "#,##0.00";
        DecimalFormat formater = new DecimalFormat(pattern);
        return "Reviews:\t" + formater.format(average) + "(" + numberOfReviews + ")" + "\n";
    }


}