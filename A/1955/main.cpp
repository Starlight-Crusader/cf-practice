#include <iostream>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int n, a, b; std::cin >> n >> a >> b;

        int fp = 0;
        if (2 * a > b)
        {
            int pairs = n / 2;
            fp += b * pairs;

            if (n % 2 != 0)
            {
                fp += a;
            }
        }
        else
        {
            fp += a * n;
        }

        std::cout << fp << '\n';
    }
}