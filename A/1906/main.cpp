#include <iostream>
#include <vector>
#include <algorithm>

#define GRID_DIM 3

/*
0 1 2
3 4 5
6 7 8
*/

int main()
{
    std::vector<char> grid(GRID_DIM * GRID_DIM);
    std::vector<std::vector<int>> adj(GRID_DIM * GRID_DIM);
    for (int i = 0; i < GRID_DIM; i++)
    {
        for (int j = 0; j < GRID_DIM; j++)
        {
            std::cin >> grid[i * GRID_DIM + j];
        
            if (i > 0)
            {
                adj[i * GRID_DIM + j].push_back((i - 1) * GRID_DIM + j);

                if (j > 0)
                {
                    adj[i * GRID_DIM + j].push_back((i - 1) * GRID_DIM + (j - 1));
                }
                
                if (j < GRID_DIM - 1)
                {
                    adj[i * GRID_DIM + j].push_back((i - 1) * GRID_DIM + (j + 1));
                }
            }
            
            if (i < GRID_DIM - 1)
            {
                adj[i * GRID_DIM + j].push_back((i + 1) * GRID_DIM + j);

                if (j > 0)
                {
                    adj[i * GRID_DIM + j].push_back((i + 1) * GRID_DIM + (j - 1));
                }
                
                if (j < GRID_DIM - 1)
                {
                    adj[i * GRID_DIM + j].push_back((i + 1) * GRID_DIM + (j + 1));
                }
            }

            if (j > 0)
            {
                adj[i * GRID_DIM + j].push_back(i * GRID_DIM + (j - 1));
            }
                
            if (j < GRID_DIM - 1)
            {
                adj[i * GRID_DIM + j].push_back(i * GRID_DIM + (j + 1));
            }

            std::sort(adj[i * GRID_DIM + j].begin(), adj[i * GRID_DIM + j].end());
        }
    }

    std::vector<char> smallest_word = {'Z', 'Z', 'Z'};
    std::vector<char> current_word;
    for (int i = 0; i < GRID_DIM * GRID_DIM; i++)
    {
        current_word.push_back(grid[i]);

        for (int c2 : adj[i])
        {
            current_word.push_back(grid[c2]);

            for (int c3 : adj[c2])
            {
                if (c3 != i)
                {
                    current_word.push_back(grid[c3]);
                    if (current_word < smallest_word)
                    {
                        smallest_word = current_word;
                    }
                    current_word.pop_back();
                }
            }

            current_word.pop_back();
        }

        current_word.pop_back();
    }

    for (char c : smallest_word)
    {
        std::cout << c;
    }

    std::cout << '\n';
}