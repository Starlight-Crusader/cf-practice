#include <iostream>
#include <vector>
#include <queue>

int countSinks(std::vector<std::vector<int>> al, std::vector<int> d, int start)
{
    std::queue<int> tq; tq.push(start);
    std::vector<bool> visited(al.size(), false);
    std::vector<int> sinks;

    while (!tq.empty())
    {
        int cur = tq.front(); tq.pop();

        if (visited[cur])
        {
            continue;
        } 
        else
        {
            visited[cur] = true;
        }

        std::vector<int> itq;
        
        for (int v : al[cur])
        {
            if (!visited[v] && d[cur] < d[v])
            {
                itq.push_back(v);
            }
        }

        if (itq.empty())
        {
            sinks.push_back(cur);
        }
        else
        {
            for (int v : itq)
            {
                tq.push(v);
            }
        }
    }

    return sinks.size();
}

std::vector<int> calcDepths(std::vector<std::vector<int>> al)
{
    std::queue<int> tq; tq.push(0);
    std::vector<bool> visited(al.size(), false);

    std::vector<int> depths(al.size(), 0);
    
    while(!tq.empty())
    {
        int cur = tq.front(); tq.pop();

        if (visited[cur])
        {
            continue;
        } 
        else
        {
            visited[cur] = true;
        }

        for (int v : al[cur])
        {
            if (!visited[v])
            {
                depths[v] = depths[cur] + 1;
                tq.push(v);
            }
        }
    }

    return depths;
}

int main()
{
    int t; std::cin >> t;

    for (int k = 0; k < t; k++)
    {
        int n; std::cin >> n;

        std::vector<std::vector<int>> tree(n);

        for (int i = 0; i < n - 1; i++)
        {
            int u, v; std::cin >> u >> v; u--; v--;

            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        int q; std::cin >> q;

        std::vector<std::vector<int>> al(q);
    
        for (int i = 0; i < q; i++)
        {
            int x, y; std::cin >> x >> y;
            al[i].push_back(x - 1);
            al[i].push_back(y - 1);
        }

        std::vector<int> d = calcDepths(tree);
        
        std::vector<int> cache(n, 0);

        for (int i = 0; i < q; i++)
        {
            int sn0 = 0;
            if (cache[al[i][0]] > 0)
            {
                sn0 = cache[al[i][0]];
            }
            else
            {
                sn0 = countSinks(tree, d, al[i][0]);
                cache[al[i][0]] = sn0;
            }

            int sn1 = 0;
            if (cache[al[i][1]] > 0)
            {
                sn1 = cache[al[i][1]];
            }
            else
            {
                sn1 = countSinks(tree, d, al[i][1]);
                cache[al[i][1]] = sn1;
            }

            std::cout << sn0 * sn1 << '\n';
        }
    }
}