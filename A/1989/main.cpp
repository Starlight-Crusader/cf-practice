#include <iostream>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int x, y; std::cin >> x >> y;

        if (y >= -1)
        {
            std::cout << "YES" << '\n';
        }
        else
        {
            std::cout << "NO" << '\n';
        }
    }
}