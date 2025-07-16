import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int t = scanner.nextInt();
        scanner.nextLine();

        for (int k = 0; k < t; k++) {
            int n = scanner.nextInt();
            scanner.nextLine();

            List<Integer> a = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int ai = scanner.nextInt();
                a.add(ai);
            }
            scanner.nextLine();

            List<Boolean> connected = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                connected.add(false);
            }
            connected.set(0, true);
            List<Integer[]> roads = new ArrayList<>();
            boolean aRoadBuilt = true;
            while (aRoadBuilt) {
                aRoadBuilt = false;

                for (int i = 0; i < n && !aRoadBuilt; i++) {
                    if (!connected.get(i)) {
                        for (int j = 0; j < n && !aRoadBuilt; j++) {
                            if (connected.get(j) && !a.get(j).equals(a.get(i))) {
                                connected.set(i, true);
                                roads.add(new Integer[] { i, j });
                                aRoadBuilt = true;
                            }
                        }
                    }
                }
            }

            if (roads.size() == n - 1) {
                System.out.println("YES");
                for (Integer[] road : roads) {
                    if (road[0] > road[1]) {
                        System.out.println(String.format("%d %d", road[1] + 1, road[0] + 1));
                    } else {
                        System.out.println(String.format("%d %d", road[0] + 1, road[1] + 1));
                    }
                }
            } else {
                System.out.println("NO");
            }
        }

        scanner.close();
    }
}