// Assignment #: 6
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30
//  Description: It needs to be filled

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.*;

public class CreatePanel extends Panel {
   private ReviewPanel rPanel;
   private JButton button1;
   private JLabel message;
   private JPanel input;
   private JLabel title;
   private JTextField titleIn;
   private JLabel publisher;
   private JTextField publisherIn;

   private JTextArea output;
   private static final long serialVersionUID = 1L;
   


	//Constructor initializes components and organize them using certain layouts
	public CreatePanel(Vector<Book> bookList, ReviewPanel rPanel){
		this.rPanel = rPanel;

		//organize components here

		setLayout(new BoxLayout(this, BoxLayout.X_AXIS));
		JPanel errorField = new JPanel();
		JPanel contentIn = new JPanel();
		JPanel buttonField = new JPanel();


		//input Panel holds the fill field and the ones containting important things.
		input = new JPanel();
		input.setLayout(new BoxLayout(input, BoxLayout.Y_AXIS));
		//first fill field
		message = new JLabel();
		message.setForeground(Color.RED);
		errorField.add(message);
		input.add(errorField);

		//content field
		contentIn.setLayout(new GridLayout(2,2));

		// content 
		title = new JLabel("Book Title:");
		contentIn.add(title);

		titleIn = new JTextField("", 10);
		contentIn.add(titleIn);

		publisher = new JLabel("Publisher:");
		contentIn.add(publisher);

		publisherIn = new JTextField("", 10);
		contentIn.add(publisherIn);

		// for the buttons
		buttonField.setLayout(new FlowLayout(FlowLayout.CENTER));
		button1 = new JButton("Create");
		button1.addActionListener(new ButtonListener());
		buttonField.add(button1);

		input.add(contentIn);
		input.add(buttonField);
		add(input);

		//output field
		String content = "No Books";
		for (int i = 0; i<bookList.size();i++) {
		  content += bookList.get(i);
		}

		output = new JTextArea(content);
		output.setForeground(Color.LIGHT_GRAY);
		output.setEditable(false);
		output.setHighlighter(null);
		JScrollPane scroll = new JScrollPane(output);
		scroll.setPreferredSize(new Dimension(700, 650));
		add(scroll);
	}

	public void updatebooklist() {
		String content = "";
		for (int i = 0; i<bookList.size();i++) {
			content += bookList.get(i);
		}
		output.setText(content);
		output.setForeground(Color.BLACK);
		message.setText("Book added");
	}


	//ButtonListener is a listener class that listens to
	//see if the buttont "Create a book" is pushed.
	//When the event occurs, it adds a book information from
	//the text fields to the text area. It also creates a Book object
	//using these two information and add it to the bookList.
	//It also does error checking.
	private class ButtonListener implements ActionListener
    {
		public void actionPerformed(ActionEvent event)
		{
			// if there is no error, add a book to book list
			// otherwise, show an error message
			try {
				Book book = new Book();
				//I used exceptions to convey what they problem is. 
				//This method has the extra bonus that if anything unexpected happens
				//the error message is displayed on the GUI.
				String titleText = titleIn.getText();
				if (titleText.equals("")) {
					throw new EmptyFieldException("Empty Title");
				}
				book.setTitle(titleText);

				String publisherText = publisherIn.getText();
				if (publisherText.equals("")) {
					throw new EmptyFieldException("Empty Publisher");
				}

				book.setPublisher(publisherText);
				bookList.add(book);
				Panel.bookList = bookList;

				updatebooklist();
			} catch (EmptyFieldException e) {
				message.setText(e.getMessage());
			}

	 } //end of actionPerformed method
  } //end of ButtonListener class
} //end of CreatePanel class