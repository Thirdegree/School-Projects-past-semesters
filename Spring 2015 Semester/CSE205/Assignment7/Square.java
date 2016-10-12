// Assignment #: 7
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30
//  Arizona State University CSE205
//  Description: It's a Square

import java.awt.*;
//also explains itself fairly well.
public class Square extends Shape {

    public Square(int x1, int y1, int width, Color color) {
        super(x1, y1, width, width, color);
    }

    public void draw(Graphics page) {
        page.setColor(color);
        page.fillRect(x1, y1, width, height);
    }

    public String toString() {
        return "Square";
    }
}