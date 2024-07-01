#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> cs(3);
    for (int i = 0; i < 3; i++)
    {
        std::cin >> cs[i];
    }

    std::vector<std::vector<char>> lcs(3);
    for (std::string c : cs)
    {
        if (c[1] == '>')
        {
            lcs[c[0] - 'A'].push_back(c[2]);
        }
        else
        {
            lcs[c[2] - 'A'].push_back(c[0]);
        }
    }

    if (lcs[0].size() == lcs[1].size() && lcs[1].size() == lcs[2].size())
    {
        std::cout << "Impossible" << '\n';
        return 0;
    }

    for (unsigned long int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (lcs[j].size() == i)
            {
                std::cout << (char)('A' + j);
                break;
            }
        }
    }

    std::cout << '\n';
}