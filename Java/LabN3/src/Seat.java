import java.util.ArrayList;
import java.util.Scanner;
public class Seat {

    public Seat(int newCost, int xPos, int yPos) {
        cost = newCost;
        this.xPos = xPos;
        this.yPos = yPos;
        isFree = true;
    }

    public int cost;
    public boolean isFree;
    public int xPos;
    public int yPos;
}
