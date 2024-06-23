#include <iostream>
#include <vector>

int main()
{
    int t; std::cin >> t;

    for (int a = 0; a < t; a++)
    {
        int n, m; std::cin >> n >> m;

        std::vector<std::vector<bool>> grid(n);
        for (int i = 0; i < n; i++)
        {
            grid[i].resize(m);

            for (int j = 0; j < m; j++)
            {
                char c; std::cin >> c;
                grid[i][j] = c == '#';
            }
        }

        int h, k;

        int ll = 0;
        for (int i = 0; i < n; i++)
        {
            h = i;
            int cl = 0;

            for (int j = 0; j < m; j++)
            {
                if (grid[i][j])
                {
                    cl++;
                }
            }

            if (cl < ll && i != 0)
            {
                h = i - 1;
                break;
            }

            ll = cl;
        }

        int k0 = -1; int k1 = -1;
        for (int j = 0; j < m; j++)
        {
            if (k0 == -1 && grid[h][j])
            {
                k0 = j;
            }

            if (k0 != -1 && grid[h][j])
            {
                k1 = j;
            }
        }

        k = k1 - abs(k1 - k0) / 2;

        std::cout << h + 1 << " " << k + 1 << "\n";
    }
}