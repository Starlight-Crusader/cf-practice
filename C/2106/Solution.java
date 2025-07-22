import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            int k = scanner.nextInt();

            int[][] ab = new int[2][n];
            int x = -1;
            int maxIdx = 0;
            int minIdx = 0;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < n; j++) {
                    ab[i][j] = scanner.nextInt();

                    if (i == 0) {
                        if (ab[i][j] < ab[0][minIdx]) {
                            minIdx = j;
                        } else if (ab[i][j] > ab[0][maxIdx]) {
                            maxIdx = j;
                        }
                    } else {
                        if (ab[i][j] != -1) {
                            x = ab[0][j] + ab[1][j];
                        }
                    }
                }
            }

            if (x != -1) {
                boolean stop = false;
                for (int i = 0; i < n && !stop; i++) {
                    if (ab[1][i] == -1) {
                        if (ab[0][i] + k < x || ab[0][i] > x) {
                            stop = true;
                        }
                    } else if (ab[0][i] + ab[1][i] != x) {
                        stop = true;
                    }
                }

                if (stop) {
                    System.out.println("0");
                } else {
                    System.out.println("1");
                }
            } else {
                System.out.println(ab[0][minIdx] + k + 1 - ab[0][maxIdx]);
            }
        }

        scanner.close();
    }
}