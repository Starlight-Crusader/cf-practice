#include <iostream>
#include <vector>

int main()
{
    int t; std::cin >> t;

    std::vector<std::vector<int>> dc(6);
    for (int i = 0; i < 6; i++)
    {
        dc[i].resize(11, -1);
    }

    while (t--)
    {
        int n, k; std::cin >> n >> k;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> a[i];
        }

        int minDiff = 9;
        for (int ai : a)
        {
            if (dc[k][ai] == -1)
            {
                int cd = ai; dc[k][ai] =  0;
                while (cd % k != 0)
                {
                    cd++; dc[k][ai]++;
                }
            }

            minDiff = std::min(minDiff, dc[k][ai]);
        }

        if (k == 4)
        {
            int ec = 0;
            for (int ai : a)
            {
                if (ai % 2 == 0)
                {
                    ec++;
                }
            }

            if (n >= 2)
            {
                minDiff = std::min(minDiff, std::max(0, 2 - ec));
            }
        }

        std::cout << minDiff << '\n';
    }
}