#include <iostream>
#include <queue>
#include <vector>

int main()
{
    int t; scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        int n, m; std::cin >> n >> m;
        int a[n][m];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cin >> a[i][j];
            } 
        }

        int nm = n * m;
        
        int depth[nm];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                depth[i * m + j] = a[i][j];
            }
        }

        std::vector<std::vector<int>> graph;
        graph.resize(nm);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 0)
                {
                    continue;
                }

                int cidx = i * m + j;
                graph[cidx].resize(4);

                if (i >= 1)
                {
                    if (a[i - 1][j] != 0)
                    {
                        graph[cidx].push_back((i - 1) * m + j);
                    }
                }

                if (i <= n - 2)
                {
                    if (a[i + 1][j] != 0)
                    {
                        graph[cidx].push_back((i + 1) * m + j);
                    }
                }

                if (j >= 1)
                {
                    if (a[i][j - 1] != 0)
                    {
                        graph[cidx].push_back(i * m + j - 1);
                    }
                }

                if (j <= m - 2)
                {
                    if (a[i][j + 1] != 0)
                    {
                        graph[cidx].push_back(i * m + j + 1);
                    } 
                }
            }
        }
    
        bool visited[nm];
        for (int i = 0; i < nm; i++)
        {
            visited[i] = false;
        }

        std::queue<int> tq;
        while (!tq.empty())
        {
            tq.pop();
        }
        
        int maxDepth = 0;

        for (int i = 0; i < nm; i++)
        {
            if (!visited[i] && depth[i] > 0)
            {
                int currDepth = 0;
                tq.push(i);

                while (!tq.empty())
                {
                    int cN = tq.front();
                    tq.pop();

                    if (visited[cN])
                    {
                        continue;
                    }

                    visited[cN] = true;
                    currDepth += depth[cN];

                    for (int v : graph[cN])
                    {
                        if (!visited[v])
                        {
                            tq.push(v);
                        }
                    }
                }
                
                maxDepth = std::max(maxDepth, currDepth);
            }
        }

        std::cout << maxDepth << '\n';
    }
}