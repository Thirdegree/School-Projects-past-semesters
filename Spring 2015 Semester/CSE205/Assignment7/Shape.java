// Assignment #: 7
//         Name: Joel Christiansen
//    StudentID: 1207242942
//      Lecture: TTH 4:30
//  Arizona State University CSE205
//  Description: When it grows up, it wants to be either a circle or a square.

import java.awt.*;
//20 lines of code to make a shape. 
public abstract class Shape {
    protected int x1;
    protected int y1;
    protected int width;
    protected int height;
    protected Color color;

    public Shape(int x1, int y1, int width, int height, Color color) {
        this.x1 = x1;
        this.y1 = y1;
        this.width = width;
        this.height = height;
        this.color = color;
    }

    public abstract void draw(Graphics page);

}