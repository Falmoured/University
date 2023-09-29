import java.util.*;
import java.lang.*;

public class Main {

    static void firstSolve() {
        System.out.println("Enter your string: ");

        Scanner in = new Scanner(System.in);

        String s = in.next();
        String maxUnique = new String();
        int maxLen = s.length();

        for (int i = 0; i < s.length(); ++i) {
            if (maxUnique.contains(String.valueOf(s.charAt(i)))){
                maxLen = maxUnique.length();
                maxUnique = new String();
                maxUnique += String.valueOf(s.charAt(i));
            }
            else {
                System.out.println(String.valueOf(s.charAt(i)));
                maxUnique += String.valueOf(s.charAt(i));
            }
            maxLen = (maxLen < maxUnique.length()) ?  maxUnique.length() : maxLen;
        }

        System.out.println(maxLen);

    }

    static void secondSolve() {
        System.out.println("Enter your mas1 and mas2: ");

        Scanner in = new Scanner(System.in);

        int[] mas1 = new int[in.nextInt()];
        int[] mas2 = new int[in.nextInt()];

        for (int i = 0; i < mas1.length; ++i)
            mas1[i] = in.nextInt();
        for (int i = 0; i < mas2.length; ++i)
            mas2[i] = in.nextInt();

        int[] mas3 = new int[(mas1.length + mas2.length)];
        System.out.println(mas3.length);

        for (int i = 0; i < mas1.length; ++i)
            mas3[i] = mas1[i];

        for (int i = mas1.length; i < (mas1.length + mas2.length); ++i)
            mas3[i] = mas2[(i - mas1.length)];

        Arrays.sort(mas3);

        for (int i = 0; i < mas3.length; ++i)
            System.out.println(mas3[i]);

    }

    static void thirdSolve(){
        System.out.println("Enter your mas: ");

        Scanner in = new Scanner(System.in);

        int[] arr = new int[in.nextInt()];
        for (int i = 0; i < arr.length; ++i)
            arr[i] = in.nextInt();

        int maxSum = arr[0];
        int maxPrevSum = 0;

        for (int i = 1; i < arr.length; ++i) {
            if (arr[i] == (arr[i-1] + 1))
                maxSum += arr[i];
            else {
                if (maxSum > maxPrevSum)  {
                    maxPrevSum = maxSum;
                    maxSum = arr[i];
                }
            }
            System.out.println(maxSum);

        }
        maxPrevSum = Math.max(maxSum,maxPrevSum);
        System.out.println(maxPrevSum);

    }

    static void fourthSolve(){
        Scanner in = new Scanner(System.in);

        int[][] array = new int[in.nextInt()][in.nextInt()];
        for (int i = 0; i < array[0].length; i++) {
            for (int j = 0; j < array.length; j++)
                array[i][j] = in.nextInt();
        }

        int[][] resultArray = new int[array[0].length][array.length];

        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array[i].length; j++)
                resultArray[j][array.length - i - 1] = array[i][j];
        }

        for (int i = 0; i < array[0].length; i++) {
            for (int j = 0; j < array.length; j++)
                System.out.println(resultArray[i][j]);
        }
    }

    static void fifthSolve(){
        Scanner in = new Scanner(System.in);

        int[] arr = new int[in.nextInt()];
        for (int i = 0; i < arr.length; ++i)
            arr[i] = in.nextInt();

        int target = in.nextInt();
        for(int i = 0; i < arr.length - 1; ++i)
            for (int j = 1; j < arr.length; ++j)
                if (arr[i] + arr[j] == target) {
                    System.out.println(arr[i] + " and " + arr[j]);
                    return;
                }

        System.out.println("null");
    }

    static void sixthSolve(){
        Scanner in = new Scanner(System.in);

        int[][] arr = new int[in.nextInt()][in.nextInt()];
        int sum = 0;

        for (int i = 0; i < arr.length; i++)
            for (int j = 0; j < arr[i].length; j++) {
                arr[i][j] = in.nextInt();
                sum += arr[i][j];
            }

        System.out.println(sum);

    }

    static void seventhSolve(){
        Scanner in = new Scanner(System.in);

        int[][] arr = new int[in.nextInt()][in.nextInt()];
        int maxRow = 0;
        int[] max = new int[arr.length];

        for (int i = 0; i < arr.length; ++i) {
            maxRow = arr[i][0];
            for (int j = 0; j < arr[i].length; ++j) {
                arr[i][j] = in.nextInt();
                maxRow = Math.max(maxRow,arr[i][j]);
                if (j == arr[i].length - 1)
                    max[i] = arr[i][j];
            }
        }

        for (int i = 0; i < max.length; ++i)
            System.out.print(max[i] + " ");

    }

    static void eighthSolve(){
        Scanner in = new Scanner(System.in);

        int[][] array = new int[in.nextInt()][in.nextInt()];
        for (int i = 0; i < array[0].length; i++) {
            for (int j = 0; j < array.length; j++)
                array[i][j] = in.nextInt();
        }

        int[][] resultArray = new int[array[0].length][array.length];

        for (int i = 0; i < array.length; i++)
            for (int j = 0; j < array[i].length; j++)
                resultArray[array[i].length - j - 1][i] = array[i][j];


        for (int i = 0; i < array[0].length; i++)
            for (int j = 0; j < array.length; j++)
                System.out.println(resultArray[i][j]);

    }

    public static void main(String[] args) {
        //firstSolve();
        //secondSolve();
        //thirdSolve();
        //fourthSolve();
        //fifthSolve();
        //sixthSolve();
        //seventhSolve();
        //eighthSolve();
    }
}