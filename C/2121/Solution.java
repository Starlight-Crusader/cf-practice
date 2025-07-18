import java.util.Scanner;
import java.util.Arrays;

public class Solution {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        for (int k = 0; k < t; k++) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();

            int[][] a = new int[n][m];
            int maxVal = 0;
            int maxValCount = 0;
            int[] rowCounts = new int[n];
            int[] colCounts = new int[m];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = scanner.nextInt();

                    if (a[i][j] > maxVal) {
                        maxVal = a[i][j];
                        maxValCount = 1;
                        Arrays.fill(rowCounts, 0);
                        Arrays.fill(colCounts, 0);
                        rowCounts[i] = 1;
                        colCounts[j] = 1;
                    } else if (a[i][j] == maxVal) {
                        maxValCount++;
                        rowCounts[i]++;
                        colCounts[j]++;
                    }
                }
            }

            boolean crossFound = false;

            for (int i = 0; i < n && !crossFound; i++) {
                for (int j = 0; j < m && !crossFound; j++) {
                    int crossCount = rowCounts[i] + colCounts[j];

                    if (a[i][j] == maxVal) {
                        crossCount--;
                    }

                    if (crossCount == maxValCount) {
                        crossFound = true;
                    }
                }
            }

            if (crossFound) {
                System.out.println(maxVal - 1);
            } else {
                System.out.println(maxVal);
            }
        }

        scanner.close();
    }
}