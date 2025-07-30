import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Solution {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();
        while (T-- > 0) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();

            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
            }

            int chainCnt = 0;

            List<List<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                adj.add(new ArrayList<>());
            }

            boolean[] vertexInMSP = new boolean[n];
            int[] minDistFromMSPVal = new int[n];
            int[] minDistFromMSPSrc = new int[n];

            Arrays.fill(minDistFromMSPVal, Integer.MAX_VALUE);
            Arrays.fill(minDistFromMSPSrc, -1);

            minDistFromMSPVal[0] = 0;
            vertexInMSP[0] = true;

            for (int count = 0; count < n - 1; count++) {
                int u = -1;

                for (int v = 0; v < n; v++) {
                    if (!vertexInMSP[v] && (u == -1 || minDistFromMSPVal[v] < minDistFromMSPVal[u])) {
                        u = v;
                    }
                }

                vertexInMSP[u] = true;

                if (minDistFromMSPSrc[u] != -1) {
                    int from = minDistFromMSPSrc[u];
                    int to = u;
                    adj.get(from).add(to);
                    adj.get(to).add(from);
                    chainCnt++;
                }

                for (int v = 0; v < n; v++) {
                    if (!vertexInMSP[v]) {
                        int dist = a[u] + a[v];

                        boolean shouldUpdate = false;

                        if (dist < minDistFromMSPVal[v]) {
                            shouldUpdate = true;
                        } else if (dist == minDistFromMSPVal[v] && minDistFromMSPSrc[v] != -1) {
                            int currentSrcDegree = adj.get(minDistFromMSPSrc[v]).size();
                            int newSrcDegree = adj.get(u).size();

                            if (newSrcDegree < currentSrcDegree) {
                                shouldUpdate = true;
                            }
                        }

                        if (shouldUpdate) {
                            minDistFromMSPVal[v] = dist;
                            minDistFromMSPSrc[v] = u;
                        }
                    }
                }
            }

            boolean failed = false;

            for (int u = 0; u < n; u++) {
                if (adj.get(u).size() == 1) {
                    int bestV = -1;
                    int bestValue = Integer.MAX_VALUE;

                    for (int v = 0; v < n; v++) {
                        if (v != u && !adj.get(u).contains(v)) {
                            if (a[v] < bestValue || (a[v] == bestValue && bestV == -1)) {
                                bestValue = a[v];
                                bestV = v;
                            }
                        }
                    }

                    if (bestV == -1) {
                        failed = true;
                        break;
                    } else {
                        adj.get(u).add(bestV);
                        adj.get(bestV).add(u);
                        chainCnt++;
                    }
                }
            }

            int totalWeight = 0;
            List<String> extraChains = new ArrayList<>();

            if (failed || m < chainCnt) {
                System.out.println(-1);
                continue;
            } else if (chainCnt < m) {
                int first = -1, second = -1;
                for (int i = 0; i < n; i++) {
                    if (first == -1 || a[i] < a[first]) {
                        second = first;
                        first = i;
                    } else if (second == -1 || a[i] < a[second]) {
                        second = i;
                    }
                }

                if (second == -1) {
                    second = (first == 0) ? 1 : 0;
                }

                int extraChainCount = m - chainCnt;
                for (int i = 0; i < extraChainCount; i++) {
                    totalWeight += a[first] + a[second];
                    extraChains.add((first + 1) + " " + (second + 1));
                }
            }

            boolean[][] visitedEdge = new boolean[n][n];
            List<String> chains = new ArrayList<>();

            for (int u = 0; u < n; u++) {
                for (int v : adj.get(u)) {
                    if (!visitedEdge[u][v]) {
                        visitedEdge[u][v] = true;
                        visitedEdge[v][u] = true;

                        totalWeight += a[u] + a[v];
                        chains.add((u + 1) + " " + (v + 1));
                    }
                }
            }

            System.out.println(totalWeight);
            for (String chain : chains) {
                System.out.println(chain);
            }
            for (String chain : extraChains) {
                System.out.println(chain);
            }
        }

        scanner.close();
    }
}