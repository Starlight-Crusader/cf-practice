#include <iostream>
#include <vector>

int main()
{
    int t; std::cin >> t;

    for (int k = 0; k < t; k++)
    {
        std::string s; std::cin >> s;
        
        std::vector<int> cnt(2, 0);
        for (char c : s)
        {
            cnt[c - '0']++;
        }

        for (int i = 0; i < s.length() + 1; i++)
        {
            if (i == s.length() || cnt[1 - (s[i] - '0')] == 0)
            {
                std::cout << s.length() - i << '\n';
                break;
            }

            cnt[1 - (s[i] - '0')]--;
        }
    }
}