#include "solution.hpp"
#include <iostream>

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution s;
    vector<int> result = s.searchRange(nums, 8);
    for (int i : result)
    {
        cout << i << " ";
    }
    return 0;
}
