#include "solution.hpp"
#include <iostream>

int main()
{
    Solution s;
    std::vector<int> nums{2, 7, 11, 15};
    int target = 9;
    auto res = s.twoSum(nums, target);
    std::cout << res[0] << ", " << res[1] << std::endl;
    return 0;
}
