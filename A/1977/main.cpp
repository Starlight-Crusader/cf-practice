#include <iostream>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int n, m; std::cin >> n >> m;

        if (m > n)
        {
            std::cout << "NO" << '\n';
        }
        else
        {
            if ((m - n) % 2 == 0)
            {
                std::cout << "YES" << '\n';
            }
            else
            {
                std::cout << "NO" << '\n';
            }
        }
    }
}