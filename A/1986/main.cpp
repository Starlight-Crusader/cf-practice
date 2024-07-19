#include <iostream>
#include <vector>
#include <algorithm>

int f(int a, std::vector<int> x)
{
    return abs(a - x[0]) + abs(a - x[1]) + abs(a - x[2]);
}

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        std::vector<int> x(3);
        for (int i = 0; i < 3; i++)
        {
            std::cin >> x[i];
        }

        std::sort(x.begin(), x.end());

        int minf = 99;
        for (int i = x[0]; i <= x[2]; i++)
        {
            minf = std::min(minf, f(i, x));
        }

        std::cout << minf << '\n';
    }
}