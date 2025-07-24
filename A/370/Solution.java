import java.util.Scanner;

public class Solution {
    private static int r1;
    private static int c1;
    private static int r2;
    private static int c2;

    private static String ans = "";

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        r1 = scanner.nextInt() - 1;
        c1 = scanner.nextInt() - 1;
        r2 = scanner.nextInt() - 1;
        c2 = scanner.nextInt() - 1;

        scanner.close();

        Runnable[] calcs = {
                Solution::calcRook,
                Solution::calcBishop,
                Solution::calcKing
        };

        for (Runnable calc : calcs) {
            if (r1 == r2 && c1 == c2) {
                ans += "0 ";
            } else {
                calc.run();
            }
        }

        System.out.flush();
        System.out.println(ans);
    }

    private static void calcRook() {
        if (r1 == r2 || c1 == c2) {
            ans += "1 ";
        } else {
            ans += "2 ";
        }
    }

    private static void calcBishop() {
        if (getTileColor(r1, c1) == getTileColor(r2, c2)) {
            if (Math.abs(r2 - r1) == Math.abs(c2 - c1)) {
                ans += "1 ";
            } else {
                ans += "2 ";
            }
        } else {
            ans += "0 ";
        }
    }

    private static void calcKing() {
        int dr = Math.abs(r2 - r1);
        int dc = Math.abs(c2 - c1);

        ans = ans + Math.max(dr, dc) + " ";
    }

    // true - light, false - dark
    private static boolean getTileColor(int row, int col) {
        if (row % 2 == 0) {
            if (col % 2 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            if (col % 2 == 0) {
                return false;
            } else {
                return true;
            }
        }
    }
}