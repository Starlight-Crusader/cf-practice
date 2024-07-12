#include <iostream>
#include <vector>
#include <limits.h>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int n; std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }

        int minmax = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            int locmax = std::max(a[i], a[i + 1]);
            minmax = std::min(minmax, locmax);
        }

        std::cout << minmax - 1 << '\n';
    }
    
}