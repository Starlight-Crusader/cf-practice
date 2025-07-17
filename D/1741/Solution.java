import java.util.Scanner;
import java.util.Arrays;

public class Solution {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        scanner.nextLine();
        for (int k = 0; k < t; k++) {
            int m = scanner.nextInt();
            scanner.nextLine();
            int[] p = new int[m];
            for (int i = 0; i < m; i++) {
                p[i] = scanner.nextInt();
            }
            scanner.nextLine();

            if (p.length == 1) {
                System.out.println("0");
            } else {
                int opNum = Solution.check(p)[2];
                System.out.println(opNum);
            }
        }

        scanner.close();
    }

    private static int[] check(int tree[]) {
        if (tree.length == 2) {
            return (tree[0] > tree[1]) ? new int[] { tree[1], tree[0], 1 } : new int[] { tree[0], tree[1], 0 };
        } else {
            int halfSize = tree.length / 2;
            int[] leftSubtree = Arrays.copyOfRange(tree, 0, halfSize);
            int[] rightSubtree = Arrays.copyOfRange(tree, halfSize, tree.length);

            int[] lCheck = Solution.check(leftSubtree);
            int[] rCheck = Solution.check(rightSubtree);

            int treeMin = (lCheck[0] < rCheck[0]) ? lCheck[0] : rCheck[0];
            int treeMax = (lCheck[1] > rCheck[1]) ? lCheck[1] : rCheck[1];
            int treeSwaps = lCheck[2] + rCheck[2];

            if (lCheck[0] == -1 || rCheck[0] == -1) {
                return new int[] { -1, -1, -1 };
            } else {
                if (lCheck[1] > rCheck[0]) {
                    if (rCheck[1] < lCheck[0]) {
                        return new int[] { treeMin, treeMax, treeSwaps + 1 };
                    } else {
                        return new int[] { -1, -1, -1 };
                    }

                } else {
                    return new int[] { treeMin, treeMax, treeSwaps };
                }
            }
        }
    }
}