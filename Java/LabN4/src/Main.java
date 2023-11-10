import java.util.Scanner;

public class Main {
    static Board board = new Board();
    static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        board.setColorGaming('w');
        board.init();
        start();
    }
    public static void start() {
        if (board.getTakeBlack().size() == 15 && board.getTakeWhite().size() == 15) {
            System.out.println("Draw!");
            end();
        }

        print_game(board);
        String inputLine = scanner.nextLine();
        if (inputLine.equals("exit")) {
            end();
        }

        int start_y, start_x, end_y, end_x;
        String[] coordinates = inputLine.split(" ");
        start_y = Integer.parseInt(coordinates[0]);
        start_x = Integer.parseInt(coordinates[1]);
        end_y = Integer.parseInt(coordinates[2]);
        end_x = Integer.parseInt(coordinates[3]);

        try {
            board.move_figure(start_y, start_x, end_y, end_x);
            if (board.getColorGaming() == 'w') {
                board.setColorGaming('b');
            } else if (board.getColorGaming() == 'b') {
                board.setColorGaming('w');
            }
        } catch (Error e) {
            System.out.println(e.getMessage());
            board.print_board();
            end();
        } finally {
            start();
        }
    }

    public static void print_game(Board board) {
        board.print_board();
        System.out.println();
        System.out.println(": ");
        System.out.println("1) exit -  Exit from the game");
        System.out.println("2) Instruction: Enter [y1 x1 y2 x2]  (x1, y1 - Figure placement) (x2, y2 - Where you want to move)");
        System.out.println("White Taken: " + board.getTakeWhite().toString());
        System.out.println("Black Taken: " + board.getTakeBlack().toString());
        if (board.getColorGaming() == 'w') {
            System.out.println("White turn - ");
        } else if (board.getColorGaming() == 'b') {
            System.out.println("Black turn - ");
        }
    }

    public static void end() {
        System.out.println();
        System.out.println("GG!");
    }
}