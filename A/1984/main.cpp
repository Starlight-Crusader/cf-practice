#include <iostream>
#include <vector>

int main()
{
    int t; std::cin >> t;

    for (int k = 0; k < t; k++)
    {
        int n; std::cin >> n;
        
        std::vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }

        bool same = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[i - 1])
            {
                same = false;
                break;
            }
        }

        if (same)
        {
            std::cout << "NO" << '\n';
        }
        else
        {
            std::cout << "YES" << '\n';

            for (int i = 0; i < n; i++)
            {
                if (i == 1)
                {
                    std::cout << 'R';
                }
                else
                {
                    std::cout << 'B';
                }
            }

            std::cout << '\n';
        }

    }
}