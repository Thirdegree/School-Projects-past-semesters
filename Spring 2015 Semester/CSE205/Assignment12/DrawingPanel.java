// Assignment #: 12
//         Name: Your name
//    StudentID: Your id
//      Lecture: Your leture days/time
//  Description: The DrawingPanel class defines a panel where dots
//               are drawn using javax.swing.Timer

import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.ArrayList;

public class DrawingPanel extends JPanel
 {
  private int diameter; //diameter of a dot
  private Color currentColor;
  private ArrayList<Dot> dotList;
  private int currentX, currentY;
  private int moveX, moveY; //how much to move horizontally or vertically
  private Timer timer;
  private int delay;   //delay of Timer
  private static final long serialVersionUID = 1L;



  //The constructor initializes instance variables, and starts the timer
  public DrawingPanel(Color color, Color backColor)
   {
    setBackground(backColor);
    currentColor = color;
    currentX = 0;
    currentY = 0;
    moveX = 3;
    moveY = 3;
    diameter = 5;
    delay = 20;
    timer = new Timer(delay, new MoveListener());


 /**********************************************************
 To be completed
**********************************************************/

   }

/**********************************************************
multiple methods to be completed
**********************************************************/

  //set the color of the dot
  public void setColor(Color another)
   {
       currentColor = another;
   }

  //get the color of the dot
  public Color getColor()
   {
       return currentColor;
   }

  //paintComponent method draws multiple dots in the dotList (done)
  public void paintComponent(Graphics page)
   {
       super.paintComponent(page);
       setBackground(Color.BLACK);

       for (int i = 0; i<dotList.size(); i++) {
        dotList.get(i).draw(page);
       }

   }

  //MoveListener defined an action to be taken for each tick of the Timer.
  //It changes the dot's x and y coordinate using moveX and moveY
  //and draw a dot with the new coordinate. The dots drawn before will
  //remain in the panel. If the dot reaches any boundary, it will rebound
  //into the opposite direction
  private class MoveListener implements ActionListener
   {
        public void actionPerformed(ActionEvent event)
          {

/**********************************************************
To be completed
**********************************************************/

          }
   }
 }
