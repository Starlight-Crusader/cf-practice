#include <iostream>
#include <vector>
#include <stack>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        std::string in; std::cin >> in;
        
        std::vector<char> out;
        std::stack<int> ll, lu;
        for (char c : in)
        {
            if (c == 'b')
            {
                if (!ll.empty())
                {
                    out[ll.top()] = '\0'; ll.pop();
                }
            }
            else if (c == 'B')
            {
                if (!lu.empty())
                {
                    out[lu.top()] = '\0'; lu.pop();
                }
            }
            else
            {
                out.push_back(c);

                if (c >= 'A' && c <= 'Z')
                {
                    lu.push(out.size() - 1);
                }
                else
                {
                    ll.push(out.size() - 1);
                }
            }
        }

        for (char oc : out)
        {
            if (oc != '\0')
            {
                std::cout << oc;
            }
        }

        std::cout << '\n';
    }    
}