// Assignment #: 6
//         Name: your name
//    StudentID: your id
//      Lecture: your lecture days/time
//  Description: It needs to be filled

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import java.util.*;

public class ReviewPanel extends Panel {
	private JTextArea title;
	private JScrollPane bookShelf;
	private JList<Book> books;
	private JPanel buttons;
	private JPanel submitHolder;
	private JRadioButton star1;
	private JRadioButton star2;
	private JRadioButton star3;
	private JRadioButton star4;
	private JRadioButton star5;
	private JButton submit;
	private DefaultListModel<Book> bookModel;
	private ButtonGroup ratings;
	private static final long serialVersionUID = 1L;




  	//Constructor initialize each component and arrange them using
  	//certain layouts
	public ReviewPanel(Vector<Book> bookList) {
		Panel.bookList = bookList;

		//organize components for review panel

		setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));

		title = new JTextArea("Choose a book to give a review, and select a rating:");
		title.setEditable(false);
		title.setHighlighter(null);
		add(title);

		//contains books
		bookShelf = new JScrollPane();

		//needed to use Jlist. Was a pain 'till I figured that out.
		bookModel = new DefaultListModel<Book>();

		//set up the Jlist
		books = new JList<Book>(bookModel);
		books.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		books.setLayoutOrientation(JList.VERTICAL);

		//I don't think this actually does anything.
		bookShelf.setPreferredSize(new Dimension(500,650));

		//allowes for scrolling of the books
		bookShelf.setViewportView(books);
		add(bookShelf);

		buttons = new JPanel();
		buttons.setLayout(new BoxLayout(buttons, BoxLayout.X_AXIS));

		star1 = new JRadioButton("1 Poor");
		star2 = new JRadioButton("2 Fair");
		star3 = new JRadioButton("3 Average");
		star4 = new JRadioButton("4 Good");
		star5 = new JRadioButton("5 Excellent");

		buttons.add(star1);
		buttons.add(star2);
		buttons.add(star3);
		buttons.add(star4);
		buttons.add(star5);

		add(buttons);

		//so that you can only select one rating at a time.
		ratings = new ButtonGroup();
		ratings.add(star1);
		ratings.add(star2);
		ratings.add(star3);
		ratings.add(star4);
		ratings.add(star5);

		submitHolder = new JPanel();
		submit = new JButton("Submit"); 
		submitHolder.add(submit);
		submit.addActionListener(new ButtonListener());

		add(submitHolder);
	}

	//This method  refreshes the JList with
	//updated vector information
	public void updatebookList() {
		//call updateUI() for the JList object
		bookList = Panel.bookList;
		//doing this every time the list is updated is probably overkill, but it's not too inefficient.
		for (int i = 0; i<bookList.size();i++) {
			if (!bookModel.contains(bookList.get(i)))
				bookModel.addElement(bookList.get(i));
		}

		books.updateUI();
 	 }


 	//RatingListener class listens to see the radio buttons
 	//to keep track of a chosen rating for a book.

 	//don't need this. keeping it because it came with the Assignment
 	//but I have better ways to do it.
 	private class RatingListener implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			//to be completed

		}
	}



 	//ButtonListener class listens to see the button "Submit Review" is pushed.
 	//A user can choose which book to give a rating/review, and that will update the
 	//average rating of such book.
 	private class ButtonListener implements ActionListener{
		public void actionPerformed(ActionEvent event){
			//get the rating from radio buttons and
			//update the average rating and the number of reviews
			//for the chosen book in the JList.
			updatebookList();
			//this took a while to figure out
			Enumeration<AbstractButton> choices = ratings.getElements();
			boolean searching = true;
			AbstractButton potential = new JRadioButton("Default");

			Book chosen = books.getSelectedValue();
			int value = 1;
		
			while (choices.hasMoreElements() && searching) {
				potential = choices.nextElement();
				if (potential.isSelected()) {
					try {
						chosen.addRating(value);
					} catch (NullPointerException e) {
						//This happens whenever you hit "Submit" and haven't selected 
						//a radio Button. The only point of the try/catch is to clean up
						//console output.
					}
 
					searching = false;
				}
				value++;

			}

			ratings.clearSelection();
			books.clearSelection();
			updatebookList();
		}
	} //end of ButtonListener class

} //end of ReviewPanel class