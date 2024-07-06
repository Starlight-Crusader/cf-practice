#include <iostream>
#include <vector>
#include <algorithm>

bool desc(int a, int b)
{
    return a > b;
}

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int n, f, k; std::cin >> n >> f >> k; f--;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }

        int fv = a[f];
        
        std::sort(a.begin(), a.end(), desc);

        if (k == n)
        {
            std::cout << "YES" << '\n';
            continue;
        }

        if (a[k] > fv)
        {
            std::cout << "NO" << '\n';
        }
        else if (a[k] < fv)
        {
            std::cout << "YES" << '\n';
        }
        else
        {
            if (a[k - 1] == a[k])
            {
                std::cout << "MAYBE" << '\n';
            }
            else
            {
                std::cout << "NO" << '\n';
            }
        }
    }
}