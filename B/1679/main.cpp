#include <iostream>
#include <vector>

int main()
{
    int n, q; std::cin >> n >> q;

    std::vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        sum += a[i];
    }
    
    int lastReplaceAllQuery = -1;
    long long lastReplaceAllQuearyVal = -1;
    std::vector<int> lastReplaceQuery(n, -1);
    std::vector<long long> lastReplaceQueryVal = a;
    for (int j = 0; j < q; j++)
    {
        int t; std::cin >> t;

        if (t == 1)
        {
            int i; long long x; std::cin >> i >> x; i--;

            long long ai;
            if (lastReplaceAllQuery > lastReplaceQuery[i])
            {
                ai = lastReplaceAllQuearyVal;
            }
            else
            {
                ai = lastReplaceQueryVal[i];
            }

            sum -= ai;
            sum += x;

            lastReplaceQuery[i] = j;
            lastReplaceQueryVal[i] = x;
        }
        else
        {
            long long x; std::cin >> x;
            
            lastReplaceAllQuery = j;
            lastReplaceAllQuearyVal = x;
            sum = x * n;
        }
    
        std::cout << sum << '\n';
    }
}