#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::string s0; std::cin >> s0;
    
    std::vector<int> pos;
    for (long unsigned int i = 0; i < s0.length(); i++)
    {
        pos.push_back(i);
    }

    std::vector<int> pb; int pbv = 0;
    for (long unsigned int i = 0; i < s0.length(); i++)
    {
        pb.push_back(pbv);

        if (s0[i] == '(')
        {
            pbv++;
        }
        else
        {
            pbv--;
        }
    }

    std::vector<std::pair<int, int>> combined(s0.length());
    for (size_t i = 0; i < s0.length(); ++i)
    {
        combined[i] = {pb[i], pos[i]};
    }

    std::sort(combined.begin(), combined.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b)
    {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    });

    std::vector<char> s(s0.length());
    for (size_t i = 0; i < combined.size(); ++i)
    {
        s[i] = s0[combined[i].second];
    }

    for (char c : s)
    {
        std::cout << c;
    }

    std::cout << '\n';
}