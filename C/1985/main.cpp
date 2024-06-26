#include <iostream>
#include <vector>

int main()
{
    int t; std::cin >> t;
    std::vector<int> ans(t);

    for (int k = 0; k < t; k++)
    {
        int n; std::cin >> n;

        long long int max = 0;
        long long int sum = 0;
        int ni = 0;

        for (int i = 0; i < n; i++)
        {
            long long int ai; std::cin >> ai;

            max = std::max(max, ai);
            sum += ai;

            if (sum - max == max)
            {
                ni++;
            }
        }

        ans[k] = ni;
    }

    for (int k = 0; k < t; k++)
    {
        std::cout << ans[k] << "\n";
    }
}