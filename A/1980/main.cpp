#include <iostream>
#include <vector>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int n, m; std::cin >> n >> m;

        std::vector<int> cc(7);
        for (int i = 0; i < n; i++)
        {
            char c; std::cin >> c;
            cc[c - 'A']++;
        }

        int nc = 0;
        for (int cci : cc)
        {
            nc += std::max(0, m - cci);
        }

        std::cout << nc << '\n';
    }
}