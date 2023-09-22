import java.util.Scanner;

public class Main {

    static void firstSolve() {
        System.out.print("First task \n");

        Scanner in = new Scanner(System.in);
        System.out.print("Enter your number: ");

        int n = in.nextInt();
        int count = 0;

        if (n == 1) {
            n = 3 * n + 1;
            ++count;
        }

        while (n != 1)
        {
            ++count;
            n = (((n % 2) == 0) ? n / 2 : 3*n+1 );
        }

        System.out.println(count);
        System.out.println("-------------");
    }

    static void secondSolve() {
        System.out.println("Second task \n");

        Scanner in = new Scanner(System.in);
        System.out.println("Enter your number: ");

        int count = in.nextInt();
        int sum = 0;

        for (int i = 0; i < count; ++i)
            sum += ( (i % 2 == 0) ? in.nextInt() : -in.nextInt() );

        System.out.println(sum);
        System.out.println("-------------");
    }

    static void thirdSolve() {
        System.out.println("Third task \n");

        Scanner in = new Scanner(System.in);
        System.out.println("Where is your hidden treasures? \n");

        int xTreas = in.nextInt();
        int yTreas = in.nextInt();

        int x = 0;
        int y = 0;

        String dir = in.nextLine();
        int count = 0;
        while (!(dir.equals("стоп"))) {
            dir = in.nextLine();
            switch(dir) {
                case "север":
                    if ((y == yTreas) && (x == xTreas)) {
                        break; }
                        else {
                            y += in.nextInt();
                            ++count;
                        }
                    break;
                case "юг":
                    if ((y == yTreas) && (x == xTreas)) {
                        break; }
                    else {
                        y -= in.nextInt();
                        ++count;
                    }
                    break;
                case "восток":
                    if ((y == yTreas) && (x == xTreas)) {
                        break; }
                    else {
                        x += in.nextInt();
                        ++count;
                    }
                    break;
                case "запад":
                    if ((y == yTreas) && (x == xTreas)) {
                        break; }
                    else {
                        x -= in.nextInt();
                        ++count;
                    }
                    break;
            }
        }
        System.out.println(count);
        System.out.println("-------------");
    }

    static void fourthSolve() {
        System.out.println("Fourth task \n");

        Scanner in = new Scanner(System.in);
        System.out.println("How many roads? \n");

        int roads = in.nextInt();
        int maxRoad = 0;
        int maxPossibly = -1;
        for (int i = 1; i <= roads; ++i)
        {
            int maxCurrHeight = 999999;
            int cTun = in.nextInt();
            for (int j = 0; j < cTun; ++j)
            {
                int currHeight = in.nextInt();
                if (maxCurrHeight > currHeight)
                    maxCurrHeight = currHeight;
            }
            if (maxPossibly < maxCurrHeight) {
                maxPossibly = maxCurrHeight;
                maxRoad = i;
            }
        }
        System.out.print(maxRoad);
        System.out.print(" ");
        System.out.println(maxPossibly);
        System.out.println("-------------");
    }

    static void fifthSolve(){
        System.out.println("Fifth solve");

        System.out.println("Enter your number: ");
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int copy = n;
         if ( (((n % 10) + ((n / 10) % 10) + (n / 100)) % 2 == 0) &&
                 (((copy % 10) * ((copy / 10) % 10) * (copy / 100)) % 2 == 0) ) {
             System.out.println("Дважды четное!");
         } else {
             System.out.println("Не дважды четное!");
         }

    }

    public static void main(String[] args) {
        //firstSolve();
        //secondSolve();
        //thirdSolve();
        //fourthSolve();
        fifthSolve();
    }
}