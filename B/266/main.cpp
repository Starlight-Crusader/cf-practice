#include <iostream>
#include <vector>

int main()
{
    int n, t; std::cin >> n >> t;

    std::vector<bool> queue(n);
    for (int i = 0; i < n; i++)
    {
        char s; std::cin >> s;
        queue[i] = s == 'B';
    }

    while (t--)
    { 
        std::vector<bool> tq;

        queue.push_back(true);
        for (int i = 0; i < n; i++)
        {
            if (queue[i] && !queue[i + 1])
            {
                tq.push_back(queue[i + 1]);
                tq.push_back(queue[i]);
                i++;
            }
            else
            {
                tq.push_back(queue[i]);
            }
        }

        queue = tq;
    }

    for (bool q : queue)
    {
        if (q)
        {
            std::cout << 'B';
        }
        else
        {
            std::cout << 'G';
        }
    }

    std::cout << '\n';
}