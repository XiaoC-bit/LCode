#pragma once
#include "../../include/utils.h"

class Solution
{
public:
    std::vector<int> twoSum(const std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> m;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            int diff = target - nums[i];
            if (m.count(diff))
            {
                return {m[diff], static_cast<int>(i)};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
