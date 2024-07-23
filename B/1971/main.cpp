#include <iostream>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        std::string s; std::cin >> s;

        bool sw = false;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[0] != s[i])
            {
                char ss = s[i]; s[i] = s[0]; s[0] = ss;
                sw = true;
                break;
            }
        }

        if (sw)
        {
            std::cout << "YES" << '\n';
            std::cout << s << '\n';
        }
        else
        {
            std::cout << "NO" << '\n';
        }
    }
}