#include <iostream>
#include <vector>

int main()
{
    int t; std::cin >> t;
    std::vector<int> ans(t, 1);
    
    for (int i = 0; i < t; i++)
    {
        std::string input; std::cin >> input;
    
        if (input[0] != '1')
        {
            ans[i] = 0;
            continue;
        }

        if (input.size() > 2)
        {
            for (unsigned long int j = 1; j < input.length() - 1; j++)
            {
                if (input[j] == '0')
                {
                    ans[i] = 0;
                    break;
                }
            }
        }

        if (input[input.length() - 1] == '9')
        {
            ans[i] = 0;
        }
    }

    for (int i = 0; i < t; i++)
    {
        switch (ans[i])
        {
        case 0:
            std::cout << "NO" << '\n';
            break;

        case 1:
            std::cout << "YES" << '\n';
            break;
        
        default:
            break;
        }
    }
}