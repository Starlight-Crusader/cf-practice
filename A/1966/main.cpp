#include <iostream>
#include <vector>
#include <utility>

#define MAX_CVAL 100

std::pair<int, int> cvalmax(std::vector<int> c)
{
    std::vector<int> cs(MAX_CVAL, 0);
    int maxC = -1;
    int maxV = -1;

    for (int ci : c)
    {
        cs[ci]++;
        
        if (cs[ci] > maxC)
        {
            maxC = cs[ci];
            maxV = ci;
        }
    }

    return std::pair<int, int>(maxV, maxC);
}

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int n, k; std::cin >> n >> k;

        std::vector<int> c(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> c[i]; c[i]--;
        }

        while (true)
        {
            std::pair<int, int> maxp = cvalmax(c);

            if (maxp.second < k)
            {
                break;
            }

            bool erased = true;
            while (erased)
            {
                erased = false;

                for (long unsigned int i = 0; i < c.size(); i++)
                {
                    if (c[i] == maxp.first)
                    {
                        c.erase(std::next(c.begin(), i));
                        erased = true;
                        break;
                    }
                }
            }

            if (c.empty())
            {
                for (int i = 0; i < k - 1; i++)
                {
                    c.push_back(0);
                }

                break;
            }
            else
            {
                for (int i = 0; i < k - 1; i++)
                {
                    c.push_back(c.back());
                }
            }
        }

        std::cout << c.size() << '\n';
    }
}