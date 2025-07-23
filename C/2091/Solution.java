import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        while (t-- > 0) {
            int n = scanner.nextInt();

            if (n % 2 == 0) {
                System.out.println(-1);
            } else if (n == 1) {
                System.out.println(1);
            } else {
                int[] perm = new int[n];

                int pivot = n / 2;
                int l = pivot - 1;
                int r = pivot + 1;

                perm[pivot] = r;

                while (l != pivot) {
                    perm[l] = ++r;

                    if (--l < 0) {
                        l = n - 1;
                    }

                    if (r > n - 1) {
                        r = 0;
                    }
                }

                for (int i = 0; i < n; i++) {
                    System.out.print(perm[i] + " ");
                }

                System.out.println();
            }
        }

        scanner.close();
    }
}