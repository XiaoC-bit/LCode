#pragma once
#include "../../include/utils.h"

class Solution
{

public:
    int lower_bound(vector<int> &nums, int target)
    {
        size_t l = 0, r = nums.size() - 1;

        size_t ans = -1;

        while (l <= r)
        {
            size_t mid = l + (r - l) / 2;
            if (nums.at(mid) == target)
            {
                ans = mid;
            }
            if (nums.at(mid) >= target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        return static_cast<int>(ans);
    }

    int upper_bound(vector<int> &nums, int target)
    {
        size_t l = 0, r = nums.size() - 1;

        size_t ans = -1;

        while (l <= r)
        {
            size_t mid = l + (r - l) / 2;
            if (nums.at(mid) == target)
            {
                ans = mid;
            }
            if (nums.at(mid) <= target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return static_cast<int>(ans);
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans(2, -1);

        ans[0] = lower_bound(nums, target);
        ans[1] = upper_bound(nums, target);

        return ans;
    }
};
