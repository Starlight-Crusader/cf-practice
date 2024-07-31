#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int n; std::cin >> n;

        std::vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end());

        int score = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            if (i % 2 == 0)
            {
                score += a[i];
            }
        }

        std::cout << score << '\n';
    }
}