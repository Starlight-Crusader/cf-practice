import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Solution {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        String t = scanner.nextLine();
        scanner.close();

        int sLen = s.length();
        int tLen = t.length();

        Map<String, Integer> abbrevCount = new HashMap<>();
        String result = null;

        for (int len = 2; len <= sLen + tLen && result == null; len++) {
            abbrevCount.clear();

            for (int prefixLen = 1; prefixLen < len && prefixLen <= sLen; prefixLen++) {
                int suffixLen = len - prefixLen;
                if (suffixLen <= 0 || suffixLen > tLen) {
                    continue;
                }

                StringBuilder sb = new StringBuilder(len);
                sb.append(s, 0, prefixLen);
                sb.append(t, tLen - suffixLen, tLen);
                String abbrev = sb.toString();

                int count = abbrevCount.getOrDefault(abbrev, 0) + 1;
                abbrevCount.put(abbrev, count);

                if (count >= 2) {
                    result = abbrev;
                    break;
                }
            }
        }

        System.out.println(result != null ? result : "-1");
    }
}