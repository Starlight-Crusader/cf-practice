#include <iostream>
#include <vector>

int main()
{
    long unsigned int t; std::cin >> t;

    std::vector<std::vector<int>> ans(t);
    while (t--)
    {
        int n, m; std::cin >> n >> m;

        std::vector<std::vector<int>> graph(n);
        while (m--)
        {
            int u, v; std::cin >> u >> v; u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int x, y;

        int pn;
        for (int i = 0; i < n; i++)
        {
            if (graph[i].size() == 1)
            {
                pn = i;
                break;
            }
        }

        int in = graph[pn][0]; x = graph[in].size() - 1;

        int cn;
        for (int u : graph[in])
        {
            if (graph[u].size() > 1)
            {
                cn = u;
                break;
            }
        }

        y = graph[cn].size();

        ans[ans.size() - t - 1].push_back(x);
        ans[ans.size() - t - 1].push_back(y);
    }

    for (long unsigned int i = 0; i < ans.size(); i++)
    {
        std::cout << ans[i][1] << ' ' << ans[i][0] << '\n';
    }
}