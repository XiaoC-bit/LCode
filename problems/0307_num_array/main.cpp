#include "solution.hpp"
#include <iostream>

int main()
{
    std::vector<int> nums = {1, 3, 5};
    NumArray numArray(nums);
    std::cout << numArray.sumRange(0, 2) << std::endl;
    return 0;
}
