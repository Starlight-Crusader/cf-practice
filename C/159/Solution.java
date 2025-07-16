import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int k = Integer.parseInt(scanner.nextLine());

        String s = scanner.nextLine();
        String t = "";
        for (int i = 0; i < k; i++) {
            t += s;
        }

        Map<Character, ArrayList<Integer>> char2Idx = new HashMap<>();
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            char2Idx.putIfAbsent(c, new ArrayList<>());
            char2Idx.get(c).add(i);
        }

        int n = Integer.parseInt(scanner.nextLine());
        StringBuilder sb = new StringBuilder(t);
        for (int i = 0; i < n; i++) {
            int p = scanner.nextInt();
            String c = scanner.nextLine().trim();

            ArrayList<Integer> cIndices = char2Idx.get(c.charAt(0));
            sb.setCharAt(cIndices.get(p - 1), ' ');
            cIndices.remove(p - 1);
        }

        for (int i = 0; i < sb.length(); i++) {
            char c = sb.charAt(i);
            if (c != ' ') {
                System.out.print(c);
            }
        }

        scanner.close();
    }
}