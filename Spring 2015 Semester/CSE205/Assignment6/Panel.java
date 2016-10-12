import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import java.util.*;

public class Panel extends JPanel {
	private static final long serialVersionUID = 1L;
	public static Vector<Book> bookList;

	protected class EmptyFieldException extends Exception {
		private static final long serialVersionUID = 1L;
		
		 public EmptyFieldException(String message) {
			super(message);
	  }
  }
}