#include <iostream>
#include <vector>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int n; std::cin >> n;

        std::vector<int> p(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> p[i]; p[i]--;
        }

        int e2 = false;
        for (int i = 0; i < n; i++)
        {
            if (i == p[p[i]]){
                e2 = true;
                break;
            }
        }

        if (e2)
        {
            std::cout << 2 << '\n';
        }
        else
        {
            std::cout << 3 << '\n';
        }
    }
}