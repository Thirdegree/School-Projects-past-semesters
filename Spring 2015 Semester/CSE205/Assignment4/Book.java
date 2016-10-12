// Assignment #: 4
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30-5:45
//  Description: This class is a representation of a Book.

public class Book {
    private String title; 
    private String publisher; 
    private Review bookReview;

    public Book() {    
        title = "?";
        publisher = "?";
        bookReview = new Review();
    }

    //getters 
    public String getTitle() {
        return title;
    }

    public String getPublisher() {
        return publisher;
    }

    public Review getBookReview() {
        return bookReview;
    }

    //setters
    public void setTitle(String title) {
        this.title = title;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    //use's the Review class's updateRating method
    public void addRating(double rating) {
        bookReview.updateRating(rating);
    }

    //custom tostring
    public String toString() {
        return String.format("\nTitle:\t%s,\n"
                            +"Publisher:\t%s,\n"
                            +"%s\n", 
                            title, publisher, bookReview);
    }
}