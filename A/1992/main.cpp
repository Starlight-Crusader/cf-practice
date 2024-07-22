#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int t; std::cin >> t;

    while (t--)
    {
        std::vector<int> nums(3);
        for (int i = 0; i < 3; i++)
        {
            std::cin >> nums[i];
        }

        for (int i = 0; i < 5; i++)
        {
            std::sort(nums.begin(), nums.end());
            nums[0]++;
        }

        int prod = 1;
        for (int i = 0; i < 3; i++)
        {
            prod *= nums[i];
        }

        std::cout << prod << '\n';
    }
}