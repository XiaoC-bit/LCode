#pragma once
#include "../../include/utils.h"

class Solution
{
public:
    /*
    给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。

注意 这个数列必须是 严格 递增的。



示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。


提示:

1 <= nums.length <= 2000
-106 <= nums[i] <= 106

    */
    int findNumberOfLIS(vector<int> &nums)
    {
        int res = 0;
        int maxLength = 0;

        // 以nums[i]结尾的最大长度
        vector<int> dp(nums.size(), 0);
        // 以nums[i]结尾的技术
        vector<int> count(nums.size(), 0);

        for (size_t i = 0; i < nums.size(); i++)
        {
            dp[i] = 1;
            count[i] = 1;

            for (size_t j = 0; j < i; j++)
            {
                if (nums[j] >= nums[i])
                    continue;

                if (dp[j] >= dp[i])
                {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                else if (dp[j] >= dp[i] - 1)
                {
                    count[i] += count[j];
                }
            }

            if (dp[i] > maxLength)
            {
                maxLength = dp[i];
                res = count[i];
            }
            else if (dp[i] == maxLength)
            {
                res += count[i];
            }
        }

        return res;
    }
};
