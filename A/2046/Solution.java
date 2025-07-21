import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();
            int[][] a = new int[2][n];

            int splitIdx = 0;

            List<Integer> tbIdx = new ArrayList<>();
            List<Integer> bbIdx = new ArrayList<>();

            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < n; j++) {
                    a[i][j] = scanner.nextInt();

                    if (i == 1 && j > 0) {
                        int colRowVal = Math.max(a[0][j], a[1][j]);
                        int colDropVal = a[0][j] + a[1][j];

                        int splitRowVal = Math.max(a[0][splitIdx], a[1][splitIdx]);
                        int splitDropVal = a[0][splitIdx] + a[1][splitIdx];

                        if (splitRowVal + colDropVal > splitDropVal + colRowVal) {
                            if (a[0][splitIdx] > a[1][splitIdx]) {
                                tbIdx.add(splitIdx);
                            } else {
                                bbIdx.add(splitIdx);
                            }
                            splitIdx = j;
                        } else {
                            if (a[0][j] > a[1][j]) {
                                tbIdx.add(j);
                            } else {
                                bbIdx.add(j);
                            }
                        }
                    }
                }
            }

            int dropSum = 0;
            for (Integer idx : tbIdx) {
                dropSum += a[0][idx];
            }
            for (Integer idx : bbIdx) {
                dropSum += a[1][idx];
            }
            dropSum = dropSum + a[0][splitIdx] + a[1][splitIdx];

            System.out.println(dropSum);
        }

        scanner.close();
    }
}