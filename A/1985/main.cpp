#include <iostream>

int main()
{
    int t; std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        std::string s1, s2; std::cin >> s1 >> s2;
        char swap = s2[0]; s2[0] = s1[0]; s1[0] = swap;
        std::cout << s1 << ' ' << s2 << '\n';
    }
}