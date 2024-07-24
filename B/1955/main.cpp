#include <iostream>
#include <vector>
#include <algorithm>

bool cv(std::vector<long long> a, std::vector<long long> b)
{
    if (a.size() != b.size())
    {
        return false;
    }

    for (unsigned long i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int n, c, d; std::cin >> n >> c >> d;
        
        std::vector<long long> b(n * n);
        for (unsigned long i = 0; i < b.size(); i++)
        {
            std::cin >> b[i];
        }

        std::sort(b.begin(), b.end());

        std::vector<long long> a(n * n, 0);
        int i = 0, j = 0; a[0] = b[0];
        while (j < n)
        {
            long long ac = a[i * n + j] + c;
            long long ad = a[i * n + j] + d;

            int xpi = i * n + (j + 1);
            if (xpi < n * n && a[xpi] == 0)
            {
                a[xpi] = ad;
            }

            int ypi = (i + 1) * n + j;
            if (ypi < n * n && a[ypi] == 0)
            {
                a[ypi] = ac;
            }

            i++;
            if (i == n)
            {
                i = 0;
                j++;
            }
        }

        std::sort(a.begin(), a.end());

        if (!cv(a, b))
        {
            std::cout << "NO" << '\n';
        }
        else
        {
            std::cout << "YES" << '\n';
        }
    }
}