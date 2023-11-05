import java.util.ArrayList;
import java.util.Scanner;
public class Hall {

    public Hall(int roomNumber,int sessionCount){
        room = roomNumber;
        Scanner in = new Scanner(System.in);

        sessions = new ArrayList<Session>();
        for (int i = 0; i < sessionCount; ++i) {
            System.out.println("Please enter info for session:" +
                    " (Film Name) (Time Start in minutes) (Film length in minutes)");
            sessions.add(new Session(in.next(), in.nextInt(),in.nextInt()));
        }


    }
    public int room;
    public ArrayList<Session> sessions;
}
