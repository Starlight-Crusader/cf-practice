#include <iostream>
#include <vector>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int n; std::cin >> n;

        std::vector<int> a; bool lastZero = false;
        std::vector<int> cnt(2, 0);
        for (int i = 0; i < n; i++)
        {
            char cai; std::cin >> cai;
            int iai = cai - '0';

            if (iai == 0)
            {
                if (!lastZero)
                {
                    lastZero = true;
                    a.push_back(iai);
                    cnt[iai]++;
                }
            }
            else
            {
                lastZero = false;
                a.push_back(iai);
                cnt[iai]++;
            }
        }

        if (cnt[1] > cnt[0])
        {
            std::cout << "YES" << '\n';
        }
        else
        {
            std::cout << "NO" << '\n';
        }
    }
}