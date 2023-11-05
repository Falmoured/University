import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);
        ArrayList<Cinema> cinemas = new ArrayList<>();

        System.out.print("How many cinemas do you want to create?");
        int cinemasCount = in.nextInt();

        for (int i = 0; i < cinemasCount; ++i) {
            System.out.print("Enter name of the cinema and halls count");
            Cinema newCinema = new Cinema(in.next(), in.nextInt());
            cinemas.add(newCinema);
        }



        boolean open = true;

        while(open) {

            System.out.print("Please choose film: ");

            for (int i = 0; i < cinemas.size(); ++i)
                cinemas.get(i).getAllFilms();


            String wantedFilm = in.next();

            for (int i = 0; i < cinemas.size(); ++i)
                cinemas.get(i).infoFilm(wantedFilm);

            System.out.print("Please choose Cinema, Hall, Session and seat (x) (y): ");

            String chosenCinema = in.next();
            int chosenHall = in.nextInt();
            int chosenSession = in.nextInt();
            int chosenX = in.nextInt();
            int chosenY = in.nextInt();

            for (int i = 0; i < cinemas.size(); ++i) {
                if (cinemas.get(i).name.equals(chosenCinema)) {
                    cinemas.get(i).buyTicket(chosenHall,chosenSession,chosenX,chosenY);
                }
            }

            open = false;
        }

    }
}
