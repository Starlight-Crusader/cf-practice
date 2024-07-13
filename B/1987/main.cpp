#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    unsigned long t; std::cin >> t;

    while (t--)
    {
        unsigned long n; std::cin >> n;
        std::vector<long long> a(n);
        
        long long p = -1;
        std::vector<long long> d;

        for (unsigned long i = 0; i < n; i++)
        {
            std::cin >> a[i];

            if (a[i] > p)
            {
                p = a[i];
            }
            else
            {
                d.push_back(p - a[i]);
            }
        }

        std::sort(d.begin(), d.end());

        long long c = 0;
        long long poc = 0;
        for (unsigned long i = 0; i < d.size(); i++)
        {
            d[i] -= poc;
            poc += d[i];
            c += d[i] * (d.size() - i + 1);
        }

        std::cout << c << '\n';
    }
}