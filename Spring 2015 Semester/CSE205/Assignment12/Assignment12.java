// Assignment #: 12
//         Name: Your name
//    StudentID: Your id
//      Lecture: Your leture days/time
//  Description: The Assignment 12 class creates control panels and
//               adds them as its Applet content and also sets its size.

import javax.swing.*;
import java.awt.*;

public class Assignment12 extends JApplet
 {
  private final int WIDTH = 650;
  private final int HEIGHT = 340;

  public void init()
   {
       ControlPanel panel1 = new ControlPanel(WIDTH, HEIGHT/2, Color.RED, Color.BLACK);
       ControlPanel panel2 = new ControlPanel(WIDTH, HEIGHT/2, Color.BLUE, Color.BLACK);
       Container cont = getContentPane();
       cont.setLayout(new GridLayout(2,1));
       cont.add(panel1);
       cont.add(panel2);

       setSize(WIDTH,HEIGHT);
   }
 }