import java.awt.*;
public class Dot {
    private int x, y;
    private Color color;
    private final int DIAMETER;

    public Dot(int x, int y, Color color, int diameter) {
        this.x = x;
        this.y = y;
        this.color = color;
        this.DIAMETER = diameter;
    }

    public void draw(Graphics page) {
        page.setColor(color);
        page.fillOval(x, y, DIAMETER, DIAMETER);
    }
}