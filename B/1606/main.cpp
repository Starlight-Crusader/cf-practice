#include <iostream>
#include <vector>

int main()
{
    int t; std::cin >> t;
    
    std::vector<long long> ans;
    while(t--)
    {
        long long k, n; std::cin >> k >> n;

        long long tc = 1;
        long long h = 0;
        while(tc < n)
        {
            tc *= 2;
            h++;
        }

        if (tc < k)
        {
            h += (k - tc + n - 1) / n;
        }

        ans.push_back(h);
    }

    for (long long a : ans)
    {
        std::cout << a << '\n';
    }
}