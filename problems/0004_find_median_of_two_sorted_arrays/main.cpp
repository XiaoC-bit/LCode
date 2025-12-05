#include "solution.hpp"
#include <iostream>

int main()
{
    Solution s;
    std::vector<int> nums1{1, 3};
    std::vector<int> nums2{2};
    auto res = s.findMedianSortedArrays(nums1, nums2);
    std::cout << res << std::endl;

    return 0;
}
