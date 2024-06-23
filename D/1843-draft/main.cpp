#include <iostream>
#include <vector>
#include <queue>

std::vector<int> calcLayers(std::vector<std::vector<int>> al)
{
    std::queue<int> tq; tq.push(0);
    std::vector<bool> visited(al.size(), false);

    std::vector<int> layers(al.size(), 0);
    
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
                layers[v] = layers[cur] + 1;
                tq.push(v);
            }
        }
    }

    return layers;
}

std::vector<std::vector<int>> compileLMap(int ml, std::vector<int> ll, std::vector<std::vector<int>> al) 
{
    std::vector<std::vector<int>> lm(ml + 1);

    for (unsigned long int i = 0; i < al.size(); i++)
    {
        lm[ll[i]].push_back(i);
    }

    return lm;
}

std::vector<std::vector<int>> lookupSrcs(int maxLayer, std::vector<int> layerList, std::vector<std::vector<int>> tree, std::vector<std::vector<int>> layerMap)
{
    std::vector<std::vector<int>> srcs(tree.size());

    for (int i = 1; i < maxLayer + 1; i++)
    {
        for (int v : layerMap[i])
        {
            for (int u : tree[v])
            {
                if (layerList[u] < layerList[v])
                {
                    srcs[v].push_back(u);

                    for (int y : srcs[u])
                    {
                        srcs[v].push_back(y);
                    }
                }
            }
        }
    }

    return srcs;
}

std::vector<int> identifySinks(std::vector<std::vector<int>> tree, std::vector<int> layerList)
{
    std::vector<int> ss;

    for (unsigned long int i = 0; i < tree.size(); i++)
    {
        bool cf = false;

        for (int v : tree[i])
        {
            if (layerList[v] > layerList[i])
            {
                cf = true;
                break;
            }
        }

        if (!cf)
        {
            ss.push_back(i);
        }
    }

    return ss;
}

int countSinks(int start, std::vector<std::vector<int>> sources, std::vector<int> sinks)
{
    int sc = 0;

    for (int sink : sinks)
    {
        if (start == sink)
        {
            return 1;
        }
    }

    for (int sink : sinks)
    {
        for (int src : sources[sink])
        {
            if (start == src)
            {
                sc++;
                break;
            }
        }
    }

    return sc;
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

        std::vector<int> layerList = calcLayers(tree);
        
        int maxLayer = 0;
        for (int i = 0; i < n; i++)
        {
            maxLayer = std::max(maxLayer, layerList[i]);
        }

        std::vector<std::vector<int>> layersMap = compileLMap(maxLayer, layerList, tree);        
        std::vector<std::vector<int>> sources = lookupSrcs(maxLayer, layerList, tree, layersMap);
        std::vector<int> sinks = identifySinks(tree, layerList);

        int q; std::cin >> q;

        std::vector<std::vector<int>> al(q);
    
        for (int i = 0; i < q; i++)
        {
            int x, y; std::cin >> x >> y;
            al[i].push_back(x - 1);
            al[i].push_back(y - 1);
        }
        
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
                sn0 = countSinks(al[i][0], sources, sinks);
                cache[al[i][0]] = sn0;
            }

            int sn1 = 0;
            if (cache[al[i][1]] > 0)
            {
                sn1 = cache[al[i][1]];
            }
            else
            {
                sn1 = countSinks(al[i][1], sources, sinks);
                cache[al[i][1]] = sn1;
            }

            std::cout << sn0 * sn1 << '\n';
        }
    }
}