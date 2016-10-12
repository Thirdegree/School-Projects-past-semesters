// Assignment #: 6
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30
//  Description: The class Book represents a book with its title and publisher.

public class Book{
	private String title;
	private String publisher;
	private Review bookReview;

	//Constructor to initialize all member variables
	public Book()
	{
		title = "?";
		publisher = "?";
		bookReview = new Review();
	}

	//Accessor method to access its title
	public String getTitle()
	{
		return title;
	}

	//Accessor method to access its publisher
	public String getPublisher()
	{
		return publisher;
	}

	//Accessor method to access its review
	public Review getBookReview()
	{
		return bookReview;
	}

	//Mutator method to access its title
	public void setTitle(String aTitle)
	{
	title = aTitle;
	}

	//Mutator method to access its publisher
	public void setPublisher(String aPublisher)
	{
		publisher = aPublisher;
	}

	//The addRating takes a new rate as its parameter
	//and updates its rating
	public void addRating(double rate)
	{
		bookReview.updateRating(rate);
	}

	//toString() method returns a string containg its title and publisher
	public String toString()
	{
		String result = "Title:\t" + title + ",\nPublisher:\t" + publisher + ",\n"
									+ bookReview.toString() + "\n\n";
		return result;
	}
}