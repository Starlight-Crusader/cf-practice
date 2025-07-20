import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();

        while (t-- > 0) {
            int n = scanner.nextInt();
            int[] a = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }

            int[] minLeft = new int[n];
            int[] maxRight = new int[n];

            minLeft[0] = Integer.MAX_VALUE;
            for (int i = 1; i < n; i++) {
                minLeft[i] = Math.min(minLeft[i - 1], a[i - 1]);
            }

            maxRight[n - 1] = Integer.MIN_VALUE;
            for (int i = n - 2; i >= 0; i--) {
                maxRight[i] = Math.max(maxRight[i + 1], a[i + 1]);
            }

            for (int i = 0; i < n; i++) {
                boolean ls = minLeft[i] < a[i];
                boolean rb = maxRight[i] > a[i];

                if (!ls || !rb) {
                    System.out.print("1");
                } else {
                    System.out.print("0");
                }
            }

            System.out.println();
        }

        scanner.close();
    }
}
