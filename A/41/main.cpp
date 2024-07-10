#include <iostream>

int main()
{
    std::string s0, s1; std::cin >> s0 >> s1;

    if (s0.length() != s1.length())
    {
        std::cout << "NO" << '\n';
        return 0;
    }

    int i = 0, j = s1.length() - 1;

    bool c = true;
    while (i < s0.length())
    {
        if (s0[i] != s1[j])
        {
            c = false;
            break;
        }

        i++;
        j--;
    }

    if (c)
    {
        std::cout << "YES" << '\n';
    }
    else
    {
        std::cout << "NO" << '\n';
    }
}