#include "solution.hpp"
#include <iostream>

int main()
{
    Solution s;
    std::vector<int> nums1 = {1, 3, 5, 2, 4};
    std::vector<int> nums2 = {6, 5, 4, 3, 2, 1, 7};
    s.nextGreaterElement(nums1, nums2);
    return 0;
}
