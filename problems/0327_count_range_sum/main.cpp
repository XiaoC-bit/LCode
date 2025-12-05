#include "solution.hpp"
#include <iostream>

int main()
{
    Solution s;
    vector<int> nums = {-2, 5, -1};
    int lower = -2;
    int upper = 2;
    s.countRangeSum(nums, lower, upper);
    return 0;
}
