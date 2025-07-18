import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        scanner.nextLine();

        for (int k = 0; k < t; k++) {
            int n = scanner.nextInt();
            scanner.nextLine();

            int[] a = new int[n];
            int[] b = new int[n];

            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }
            scanner.nextLine();

            for (int i = 0; i < n; i++) {
                b[i] = scanner.nextInt();
            }
            scanner.nextLine();

            List<Integer[]> operations = new ArrayList<>();

            sort(a, 1, operations);
            sort(b, 2, operations);

            for (int i = 0; i < n; i++) {
                if (a[i] > b[i]) {
                    opOutSwap(a, b, i, operations);
                }
            }

            System.out.println(operations.size());
            for (Integer[] op : operations) {
                System.out.println(op[0] + " " + op[1]);
            }
        }

        scanner.close();
    }

    public static void opInSwap(int[] arr, int i, int arrIdx, List<Integer[]> opArr) {
        int tmp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = tmp;

        opArr.add(new Integer[] { arrIdx, i + 1 });
    }

    public static void opOutSwap(int[] a, int[] b, int i, List<Integer[]> opArr) {
        int tmp = a[i];
        a[i] = b[i];
        b[i] = tmp;

        opArr.add(new Integer[] { 3, i + 1 });
    }

    public static void sort(int[] arr, int arrIdx, List<Integer[]> opArr) {
        int n = arr.length;
        boolean swapped;
        for (int pass = 0; pass < n - 1; pass++) {
            swapped = false;
            for (int i = 0; i < n - pass - 1; i++) {
                if (arr[i] > arr[i + 1]) {
                    opInSwap(arr, i, arrIdx, opArr);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }
}