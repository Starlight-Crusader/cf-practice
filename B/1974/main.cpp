#include <iostream>
#include <vector>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        int b; std::cin >> b;
        std::string s; std::cin >> s;

        std::vector<bool> dl(26, false);
        for (char c : s)
        {
            dl[c - 'a'] = true;
        }

        std::vector<char> la;
        for (unsigned long i = 0; i < dl.size(); i++)
        {
            if (dl[i])
            {
                la.push_back('a' + i);
            }
        }

        if (la.size() == 1)
        {
            std::cout << s << '\n';
            continue;
        }

        std::vector<char> tt(26, '\0');
        for (unsigned long i = 0; i < la.size() / 2; i++)
        {
            char l0 = la[i];
            char l1 = la[la.size() - i - 1];

            tt[l0 - 'a'] = l1;
            tt[l1 - 'a'] = l0;
        }

        if (la.size() % 2 != 0)
        {
            char c = la[la.size() / 2];
            tt[c - 'a'] = c;
        }

        std::vector<char> ts;
        for (char c : s)
        {
            ts.push_back(tt[c - 'a']);
        }

        for (char c : ts)
        {
            std::cout << c;
        }

        std::cout << '\n';
    }
}