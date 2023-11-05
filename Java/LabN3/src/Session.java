import java.util.ArrayList;
import java.util.Scanner;
 class Session {

    public Session (String newFilmName, int newTimeStart, int newFilmTime) {
        filmName = newFilmName;
        filmTime = newFilmTime;
        timeStart = newTimeStart;

         System.out.println("Please enter seats position for your session" +
                ": (Session avaliable seats set with your NxN parameters)" +
                " (( After NxN parameters enter" +
                " how many seats avaliable with cost, x and y coords for current seat [without errors] ))");

        seats = new ArrayList<Seat>();

        Scanner in = new Scanner(System.in);
        seatsMap = new boolean[in.nextInt()][in.nextInt()];
        seatsCount = in.nextInt();
        seats = new ArrayList<Seat>();

        for (int i = 0; i < seatsCount; ++i) {
            Seat seat = new Seat(in.nextInt(), in.nextInt(),in.nextInt());
            seats.add(seat);

            seatsMap[seats.get(i).xPos][seats.get(i).yPos] = true;
        }


    }

    public void getTimeStart(){
        if ( (timeStart / 60 < 10) && (timeStart % 60 < 10) )
            System.out.print("0" + timeStart / 60 + ":" + "0" + timeStart % 60);
        if ( (timeStart / 60 < 10) && (timeStart % 60 > 10) )
            System.out.print("0" + timeStart / 60 + ":" + timeStart % 60);
        if ( (timeStart / 60 > 10) && (timeStart % 60 < 10) )
            System.out.print(timeStart / 60 + ":" + "0" + timeStart % 60);
        if ( (timeStart / 60 > 10) && (timeStart % 60 > 10) )
            System.out.print(timeStart / 60 + ":" + timeStart % 60);
     }

     void buyTicket(int x, int y){
         for(int i = 0; i < seatsCount; ++i) {
             if ((seats.get(i).xPos == x) && (seats.get(i).yPos == y))
                 seats.get(i).isFree = false;
         }
     }

     public void getSeatsMap() {
        for (int i = 0; i < seatsMap.length; ++i) {
            System.out.println();
            for (int j = 0; j < seatsMap[0].length; ++j) {
                if (seatsMap[i][j])
                    System.out.print(" x ");
                else
                    System.out.print(" - ");
            }
        }
     }

     public void refreshSeatsMap() {
        for (int i = 0; i < seatsCount; ++i)
            if (seats.get(i).isFree == false)
                seatsMap[seats.get(i).xPos][seats.get(i).yPos] = false;
     }
    public String filmName;
    public int filmTime;
    public int timeStart;
    public ArrayList<Seat> seats;
    public boolean[][] seatsMap;
    private int seatsCount;

}
