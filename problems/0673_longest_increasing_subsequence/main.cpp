#include "solution.hpp"
#include <iostream>

int main()
{
    Solution s;
    std::vector<int> nums = {1, 3, 5, 4, 7};
    std::cout << s.findNumberOfLIS(nums) << std::endl;
    return 0;
}
