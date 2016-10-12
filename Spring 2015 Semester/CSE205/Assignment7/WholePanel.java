// Assignment #: 7
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30
//  Arizona State University CSE205
//  Description: The actually difficult part, with all the difficult parts pre-filled for our convience. 

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.ArrayList;

public class WholePanel extends JPanel
{
   //lots of variables. Lots.

   //defaults first
   private Color currentColor;
   private String colorString;
   private String shape;
   private int size;

   //storage
   private ArrayList<Shape> shapeList;

   //instructions for the user
   private JLabel message = new JLabel("Choose Circle or Square, its size, and its color.");

   //next the top panel stuff
   private JPanel topPanel;
   private JComboBox<Integer> sizeCombo;
   private JComboBox<String> shapeCombo;
   private JComboBox<String> colorCombo;
   private JButton undo;

   //to paint!
   private CanvasPanel canvas;
   
   //ComboBox contents
   private Integer[] sizes = {10, 20, 30, 40, 50};
   private String[] shapes = {"Circle", "Square"};
   private String[] colors = {"Black", "Red", "Blue", "Green", "Orange"};

   //positioning of the shapes, (x1, y1) = center of the shape   
   private int x1;
   private int y1;

   //I don't know why my compiler wants this, but it really, really does.
   private static final long serialVersionUID = 1L;

   
   public WholePanel()
   {
      //defining defaults
      currentColor = Color.black;
      colorString = "Black";
      shape = "Circle";
      size = 10;

      //List that will hold all shapes that need to be drawn on the page
      shapeList = new ArrayList<Shape>();

      //Yay buttons!
      undo = new JButton ("Undo");
      undo.addActionListener(new ButtonListener());

      //Drop down menues!
      shapeCombo = new JComboBox<String>(shapes);
      shapeCombo.addActionListener(new ComboListener());
      sizeCombo = new JComboBox<Integer>(sizes);
      sizeCombo.addActionListener(new ComboListener());
      colorCombo = new JComboBox<String>(colors);
      colorCombo.addActionListener(new ComboListener());

      //Upper portion of the drawing window holds drop down menuse and buttons
      topPanel = new JPanel();
      topPanel.add(shapeCombo);
      topPanel.add(sizeCombo);
      topPanel.add(colorCombo);
      topPanel.add(undo);

      //to paint a pretty picture
      canvas = new CanvasPanel();
      canvas.addMouseListener(new PointListener());


      JSplitPane sp = new JSplitPane(JSplitPane.VERTICAL_SPLIT, topPanel, canvas);

      //put it all togeather, and what do you get?
      setLayout(new BorderLayout());
      add(message, BorderLayout.NORTH);
      add(sp);
    }

  //CanvasPanel is the panel where shapes will be drawn
  private class CanvasPanel extends JPanel
   {
      private static final long serialVersionUID = 1L;

      //this method draws all shapes specified by a user
      public void paintComponent(Graphics page)
       {
        //some weirdness with the background happens without this
        super.paintComponent(page); 


        setBackground(Color.WHITE);

        //draw all the shapes.
        for (int i = 0; i<shapeList.size(); i++) {
          shapeList.get(i).draw(page);
        }

       }
    } //end of CanvasPanel class


   //ButtonListener defined actions to take in case
   //"Undo" is chosed.
   private class ButtonListener implements ActionListener
    {
      public void actionPerformed (ActionEvent event)
      {
          //needs to be filled
        //terminal output compains if this isn't in an if. Doesn't kill the program, oh no. Just complains.
        if (shapeList.size()>0) {
          shapeList.remove(shapeList.size()-1);
        }
        //repaint the pretty picture
        repaint();
      }
   } // end of ButtonListener


   // listener class to set the color chosen by a user using
   // color combo box, set the size chosen using size combo box
   // or set the shape (circle or square) using shape combo box
   private class ComboListener implements ActionListener
    {
        public void actionPerformed(ActionEvent event)
         {
          //wish there was a more elegant way to do this, this is ugly. I guess you could do 3 seperate
          //listers, but ewww.
          if(event.getSource() == shapeCombo) {
            shape = (String) shapeCombo.getSelectedItem();
          }

          else if (event.getSource() == sizeCombo) {
            size = (int) sizeCombo.getSelectedItem();
          }

          else if (event.getSource() == colorCombo) {

            colorString = (String) colorCombo.getSelectedItem();

            //I don't usually align like that, but it looks too nice here not to.
            switch(colorString) {
              case "Black" : currentColor = Color.BLACK;  break;
              case "Blue"  : currentColor = Color.BLUE;   break;
              case "Red"   : currentColor = Color.RED;    break;
              case "Green" : currentColor = Color.GREEN;  break;
              case "Orange": currentColor = Color.ORANGE; break;
            }

          }
         }
    } // end of ComboListener


   // listener class that listens to the mouse
   public class PointListener implements MouseListener
    {
     //in case that a user presses using a mouse,
     //record the point where it was pressed.
     public void mousePressed (MouseEvent event)
      {
         /*

         x_________
         |         |    . = where you click
         |         |    x = where the Graphics methods want to start drawing
         |    .    |    _________ = size
         |         |    _____ = size/2
         |_________|    x = . (-) _____ for x and y
         
         */
                        
          x1 = event.getX() - size/2;
          y1 = event.getY() - size/2;

          //hey, it alignes itself this time!
          switch(shape) {
            case "Circle" : shapeList.add(new Circle(x1, y1, size, currentColor)); break;
            case "Square" : shapeList.add(new Square(x1, y1, size, currentColor)); break;
          }
          canvas.repaint();
      }


     public void mouseReleased (MouseEvent event) {}
     public void mouseClicked (MouseEvent event) {}
     public void mouseEntered (MouseEvent event) {}
     public void mouseExited (MouseEvent event) {}

    } // end of PointListener

} // end of Whole Panel Class