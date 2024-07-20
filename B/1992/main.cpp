#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int n, k; std::cin >> n >> k;

        std::vector<int> a(k);
        for (int i = 0; i < k; i++)
        {
            std::cin >> a[i];
        }

        std::sort(a.begin(), a.end());

        int oc = 0;
        for (int i = 0; i < k - 1; i++)
        {
            oc += a[i] - 1 + a[i];
        }

        std::cout << oc << '\n';
    }
}