#include <iostream>
#include <vector>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int n, m, k; std::cin >> n >> m >> k;

        std::vector<int> b(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> b[i];
        }
        
        std::vector<int> c(m);
        for (int i = 0; i < m; i++)
        {
            std::cin >> c[i];
        }

        int wCnt = 0;
        for (int bi : b)
        {
            for (int ci : c)
            {
                if (bi + ci <= k)
                {
                    wCnt++;
                }
            }
        }

        std::cout << wCnt << '\n';
    }
}