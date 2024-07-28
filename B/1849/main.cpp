#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int n, k; std::cin >> n >> k;

        std::deque<std::pair<int, int>> dq;
        for (int i = 0; i < n; i++)
        {
            int hp; std::cin >> hp; hp %= k;
            if (!hp)
            {
                hp = k;
            }

            dq.push_back(std::make_pair(i + 1, hp));
        }

        std::sort(dq.begin(), dq.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second < b.second || (a.second == b.second && a.first > b.first);
        });

        while (!dq.empty()) {
            auto current = dq.back(); dq.pop_back();

            current.second -= k;
            if (current.second <= 0)
            {
                std::cout << current.first << ' ';
            }
            else
            {
                auto it = std::upper_bound(dq.begin(), dq.end(), current, [](const std::pair<int, int>& a, const std::pair<int, int>& b)
                {
                    return a.second < b.second || (a.second == b.second && a.first > b.first);
                });
                dq.insert(it, current);
            }
        }

        std::cout << '\n';
    }

    return 0;
}