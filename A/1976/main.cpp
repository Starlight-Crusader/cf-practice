#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compareAscending(int a, int b)
{
    return a < b;
}

int main()
{
    int t; std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n; std::cin >> n;

        std::string input; std::cin >> input;

        std::vector<int> codeArray;
        for (char c : input)
        {
            codeArray.push_back(static_cast<int>(c));
        }

        std::vector<int> digitsArray;
        std::vector<int> lettersArray;
        if (codeArray[0] >= 0x30 && codeArray[0] <= 0x39)
        {
            digitsArray.push_back(codeArray[0]);
        }
        else
        {
            lettersArray.push_back(codeArray[0]);
        }

        bool c0 = true;
        for (long unsigned int j = 1; j < codeArray.size(); j++)
        {
            if (codeArray[j] >= 0x30 && codeArray[j] <= 0x39)
            {
                digitsArray.push_back(codeArray[j]);

                if (codeArray[j - 1] >= 0x61 && codeArray[j - 1] <= 0x7A)
                {
                    c0 = false;
                    break;
                }
            }
            else
            {
                lettersArray.push_back(codeArray[j]);
            }
        }

        if (!c0)
        {
            std::cout << "NO" << '\n';
            continue;
        }

        std::vector<int> dSortBuffer = digitsArray;
        std::vector<int> lSortBuffer = lettersArray;

        std::sort(dSortBuffer.begin(), dSortBuffer.end(), compareAscending);
        std::sort(lSortBuffer.begin(), lSortBuffer.end(), compareAscending);

        bool c1 = true;
        for (long unsigned int j = 0; j < digitsArray.size(); j++)
        {
            if (digitsArray[j] != dSortBuffer[j])
            {
                c1 = false;
                break;
            }
        }

        if (!c1)
        {
            std::cout << "NO" << '\n';
            continue;
        }

        bool c2 = true;
        for (long unsigned int j = 0; j < lettersArray.size(); j++)
        {
            if (lettersArray[j] != lSortBuffer[j])
            {
                c2 = false;
                break;
            }
        }

        if (!c2)
        {
            std::cout << "NO" << '\n';
            continue;
        }

        std::cout << "YES" << '\n';
    }
}