#include <iostream>
#include <vector>

int main()
{
    int t; std::cin >> t;

    for (int k = 0; k < t; k++)
    {
        std::vector<int> abcd(4);
        std::vector<bool> ab(4);  
    
        for (int j = 0; j < 4; j++)
        {
            std::cin >> abcd[j];
        }

        ab[0] = true;
        ab[1] = true;
        ab[2] = false;
        ab[3] = false;

        for (int i = 0; i < 4 - 1; i++)
        {
            for (int j = 0; j < 4 - i - 1; j++)
            {
                if (abcd[j] > abcd[j + 1])
                {
                    int resI = abcd[j];
                    abcd[j] = abcd[j + 1];
                    abcd[j + 1] = resI;

                    bool resB = ab[j];
                    ab[j] = ab[j + 1];
                    ab[j + 1] = resB;
                }
            }
        }

        bool c0 = ab[0] != ab[1];
        bool c1 = ab[1] != ab[2];
        bool c2 = ab[2] != ab[3];

        if (c0 && c1 && c2)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
    }
}