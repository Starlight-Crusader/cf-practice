#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int t; std::cin >> t;

    std::vector<std::string> ans;
    for (int k = 0; k < t; k++)
    {
        int n, m; std::cin >> n >> m;
        std::string s; std::cin >> s;

        std::vector<int> ind0(m);
        for (int i = 0; i < m; i++)
        {
            std::cin >> ind0[i];
            ind0[i]--;
        }

        std::vector<char> c(m);
        for (int i = 0; i < m; i++)
        {
            std::cin >> c[i];
        }

        std::sort(c.begin(), c.end());

        std::vector<int> occ(n);
        for (int idx : ind0)
        {
            occ[idx]++;   
        }

        std::vector<int> ind;
        for (int i = 0; i < n; i++)
        {
            occ[i]--;
            if (occ[i] >= 0)
            {
                ind.push_back(i);
            }
        }

        for (int i = 0; i < n; i++)
        {
            while (occ[i] > 0)
            {
                ind.push_back(i);
                occ[i]--;
            }
        }

        for (int i = m - 1; i >= 0; i--)
        {
            s[ind[i]] = c[i];
        }

        ans.push_back(s);
    }

    for (int i = 0; i < t; i++)
    {
        std::cout << ans[i] << '\n';
    }
}