#include <iostream>
#include <climits>

int main()
{
    int t; std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n; std::cin >> n;
        
        long long a[n];
        for (int j = 0; j < n; j++)
        {
            std::cin >> a[j];
        }

        long long b[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            std::cin >> b[j];
        }

        long long opNum = 0;
        long long minExt = LLONG_MAX;
        for (long long j = 0; j < n; j++)
        {
            opNum += abs(b[j] - a[j]); 

            minExt = std::min(minExt, static_cast<long long>(abs(b[n] - a[j])));
            minExt = std::min(minExt, static_cast<long long>(abs(b[n] - b[j])));

            if (std::min(a[j], b[j]) <= b[n] && b[n] <= std::max(a[j], b[j]))
            {
                minExt = 0;
            }
        }

        std::cout << opNum + minExt + 1 << '\n';
    }
}