// Assignment #: 7
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30
//  Arizona State University CSE205
//  Description: It's a circle.

import java.awt.*;
//fairly self explanatory in general really.
public class Circle extends Shape {

    public Circle(int x1, int y1, int diameter, Color color) {
        super(x1, y1, diameter, diameter, color);
    }

    public void draw(Graphics page) {
        page.setColor(color);
        page.fillOval(x1, y1, width, height);
    }

    //this made debugging a bit easier. Way better than the default for sure.
    public String toString() {
        return "Circle";
    }
}