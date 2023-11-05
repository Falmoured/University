import java.util.ArrayList;
import java.util.Scanner;

public class Cinema {
    public Cinema (String newName, int countHalls) {

        countCinema += 1;
        name = newName;
        Scanner in = new Scanner(System.in);

        halls = new ArrayList<Hall>();
        for (int i = 0; i < countHalls; ++i) {
            System.out.println("Please enter info for hall:" +
                    " (room) (sessions count)");
            halls.add(new Hall(in.nextInt(), in.nextInt()));
        }
    }

    void getAllFilms() {
        for (int i = 0; i < halls.size(); ++i) {
            for (int j = 0; j < halls.get(i).sessions.size(); ++j)
                System.out.print(halls.get(i).sessions.get(j).filmName + " ");
        }
    }

    void infoFilm(String findFilmName) {
        Hall actionHall;
        Session actionSession;
        Scanner in = new Scanner(System.in);

        for (int i = 0; i < halls.size(); ++i) {
            for (int j = 0; j < halls.get(i).sessions.size(); ++j)
                if (halls.get(i).sessions.get(j).filmName.equals(findFilmName)) {
                    actionHall = halls.get(i);
                    actionSession = halls.get(i).sessions.get(j);

                    System.out.print("Cinema: " + name + " Hall: " + actionHall.room
                            + " Time start: ");
                    actionSession.getTimeStart();
                    System.out.println();


                    System.out.println("Seats: (x = free)");
                    actionSession.getSeatsMap();

                    //buyTicket(in.nextInt(),in.nextInt());

                }
        }
    }

    void buyTicket(int hRoom, int nSession, int x, int y) {
        int sellCost = 0;
        for (int i = 0; i < halls.get(hRoom-1).sessions.get(nSession-1).seats.size(); ++i)
            if ( (halls.get(hRoom-1).sessions.get(nSession-1).seats.get(i).xPos == x)
                && ( halls.get(hRoom-1).sessions.get(nSession-1).seats.get(i).yPos == y) ) {
                halls.get(hRoom - 1).sessions.get(nSession - 1).seats.get(i).isFree = false;
                sellCost = halls.get(hRoom - 1).sessions.get(nSession - 1).seats.get(i).cost;
            }
        halls.get(hRoom-1).sessions.get(nSession-1).refreshSeatsMap();
        System.out.println("You bought ticket for: " + sellCost);
        halls.get(hRoom-1).sessions.get(nSession-1).getSeatsMap();
    }
    /*public Cinema (String newName, boolean f){
        countCinema += 1;
        System.out.print("created");
    }*/


    public static int countCinema = 0;
    public String name;
    public ArrayList<Hall> halls;
}
