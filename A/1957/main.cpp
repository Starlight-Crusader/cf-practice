#include <iostream>
#include <vector>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int n; std::cin >> n;

        std::vector<int> ca; ca.clear();
        for (int i = 0; i < n; i++)
        {
            int ai; std::cin >> ai;

            int m = std::max(0, static_cast<int>(ai - ca.size()));
            for (int j = 0; j < m; j++)
            {
                ca.push_back(0);
            }

            ca[ai - 1]++;
        }

        int cnt = 0;
        for (int cai : ca)
        {
            cnt += cai / 3;
        }

        std::cout << cnt << '\n';
    }
}