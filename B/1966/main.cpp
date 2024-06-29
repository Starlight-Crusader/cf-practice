#include <iostream>
#include <vector>

int main()
{
    int t; std::cin >> t;
    
    std::vector<bool> anss;
    for (int k = 0; k < t; k++)
    {
        int n, m; std::cin >> n >> m;

        std::vector<std::vector<bool>> grid(n);
        for (int i = 0; i < n; i++)
        {
            grid[i].resize(m);
            for (int j = 0; j < m; j++)
            {
                char c; std::cin >> c;
                grid[i][j] = c == 'W';
            }
        }

        bool r1e = true;
        bool rne = true;
        bool c1e = true;
        bool cme = true;

        for (int j = 1; j < m; j++)
        {
            if (grid[0][j] != grid[0][j - 1])
            {
                r1e = false;
            }

            if (grid[n - 1][j] != grid[n - 1][j - 1])
            {
                rne = false;
            }
        }

        if (r1e && rne && grid[0][0] != grid[n - 1][m - 1])
        {
            anss.push_back(false);
            continue;
        }

        for (int i = 1; i < n; i++)
        {
            if (grid[i][0] != grid[i - 1][0])
            {
                c1e = false;
            }

            if (grid[i][m - 1] != grid[i - 1][m - 1])
            {
                cme = false;
            }
        }

        if (c1e && cme && grid[0][0] != grid[n - 1][m - 1])
        {
            anss.push_back(false);
            continue;
        }

        anss.push_back(true);
    }

    for (bool b : anss)
    {
        if (b)
        {
            std::cout << "YES" << '\n';
        }
        else
        {
            std::cout << "NO" << '\n';
        }
    }
}