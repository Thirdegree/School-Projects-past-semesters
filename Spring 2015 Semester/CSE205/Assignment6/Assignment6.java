// Assignment #: 6
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30
//  Description: The Assignment 6 class creates a Tabbed Pane with
//               two tabs, one for Book creation and one for
//               Book review. and adds it as its Applet content
//               and also sets its size.

import javax.swing.*;
import javax.swing.event.*;
import java.util.*;

public class Assignment6 extends JApplet {
	private int APPLET_WIDTH = 650, APPLET_HEIGHT = 350;

	private JTabbedPane tPane;
	private CreatePanel createPanel;
	private ReviewPanel reviewPanel;
	private Vector<Book> bookList;
	private static final long serialVersionUID = 1L;


	//The method init initializes the Applet with a Pane with two tabs
	public void init()
	{
		//list of books to be used in every panel
		bookList = new Vector<Book>();

		//review panel uses the list of books
		reviewPanel = new ReviewPanel(bookList);

		createPanel = new CreatePanel(bookList, reviewPanel);

		//create a tabbed pane with two tabs
		tPane = new JTabbedPane();
		tPane.addTab("Book creation", createPanel);
		tPane.addTab("Book review", reviewPanel);
		tPane.addChangeListener(new TabChangeListener());

		getContentPane().add(tPane);
		setSize (APPLET_WIDTH, APPLET_HEIGHT); //set Applet size
	}

	private class TabChangeListener implements ChangeListener {
		public void stateChanged(ChangeEvent e) {
			reviewPanel.updatebookList();
			createPanel.updatebooklist();
		}
	}
}

