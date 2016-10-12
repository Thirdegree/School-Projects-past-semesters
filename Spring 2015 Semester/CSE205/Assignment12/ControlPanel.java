// Assignment #: 12
//         Name: Your name
//    StudentID: Your id
//      Lecture: Your leture days/time
//  Description: The ControlPane class creates 5 buttons and 1 slider to
//               to control the movement of a ball

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.event.*;

public class ControlPanel extends JPanel
 {
  private DrawingPanel drawing;
  private JButton start, stop, reverseX, reverseY, changeColor;
  private JSlider slider1;
  private JLabel label1;
  private JPanel buttons1, panel1, leftPanel;
  private JColorChooser chooser;
  private int width, height;
  private static final long serialVersionUID = 1L;


  //The constructor creates 5 buttons, 1 sliders, and 1 drawing panel
  //and organize them using layouts.
  public ControlPanel(int width, int height, Color foregroundColor, Color backgroundColor)
   {
       this.width = width;
       this.height = height;

       //create a drawing panel
       drawing = new DrawingPanel(foregroundColor, backgroundColor);

       //create 5 buttons, start, stop, up, reverseX, reverseY, changeColor
       start = new JButton("Start");
       stop = new JButton("Stop");
       reverseX = new JButton("Reverse X");
       reverseY = new JButton("Reverse Y");
       changeColor = new JButton("Change Color");


       start.addActionListener(new ButtonListener());
       stop.addActionListener(new ButtonListener());
       reverseX.addActionListener(new ButtonListener());
       reverseY.addActionListener(new ButtonListener());
       changeColor.addActionListener(new ButtonListener());

       buttons1 = new JPanel();
       buttons1.setLayout(new GridLayout(5,1));

       buttons1.add(start);
       buttons1.add(stop);
       buttons1.add(reverseX);
       buttons1.add(reverseY);
       buttons1.add(changeColor);

       //Color Chooser will let a user select a color.
       //This is used in the Button Listener
       chooser = new JColorChooser();

       //create a slider with major tick spacing 10,
       //minor tick spacing 1. The minimum value is 0, the maximum
       //is 50, and the initial set value is 20.
       slider1 = new JSlider(JSlider.VERTICAL, 0, 50, 20);
       slider1.setMajorTickSpacing(10);
       slider1.setMinorTickSpacing(1);
       slider1.setPaintTicks(true);
       slider1.setPaintLabels(true);
       slider1.setAlignmentX(Component.LEFT_ALIGNMENT);
       slider1.addChangeListener(new SliderListener());


       //create a label to be shown above each slider.
       label1 = new JLabel("Delay");

       //organize buttons, a slider, and a label for the ball
       panel1 = new JPanel(new BorderLayout());
       panel1.add(label1, BorderLayout.NORTH);
       panel1.add(slider1, BorderLayout.CENTER);

       leftPanel = new JPanel(new BorderLayout());
       leftPanel.add(buttons1, BorderLayout.CENTER);
       leftPanel.add(panel1, BorderLayout.EAST);


       //organize the button panel and the drawing panel using SplitPane
       setLayout(new BorderLayout());
       drawing.setPreferredSize(new Dimension((width*3)/4, height));
       JSplitPane sp = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, leftPanel, drawing);
       add(sp);

       setPreferredSize(new Dimension(width,height));
    }


  //ButtonListener defines actions to be performed when each button
  //is pushed.
  private class ButtonListener implements ActionListener
   {
       public void actionPerformed(ActionEvent event)
        {
            Object action = event.getSource();

            if (action == changeColor)
             {
                 Color currentColor = drawing.getColor();
                 Color newColor = chooser.showDialog(null, "Change Color", currentColor);
                 drawing.setColor(newColor);
             }

             if (action == start) {
              drawing.resume();
             }

             if (action == stop) {
              drawing.suspend();
             }

             if (action == reverseX) {
              drawing.reverseX(); 
             }

             if (action == reverseY) {
              drawing.reverseY();
             }
/**********************************************************
To be completed for other buttons
**********************************************************/


         }
     } //end of ButtonListener

   //SliderListener adjust the delay of each dot based on
   //the chosen integer in the corresponding slider.
   private class SliderListener implements ChangeListener
    {
        public void stateChanged(ChangeEvent event)
         {

/**********************************************************
To be completed
**********************************************************/

         }

     } //end of SliderListener

}