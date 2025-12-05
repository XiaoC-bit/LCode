#pragma once
#include "../../include/utils.h"

/**
 *
 *
 * 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。

你需要返回给定数组中的重要翻转对的数量。

示例 1:

输入: [1,3,2,3,1]
输出: 2
示例 2:

输入: [2,4,3,5,1]
输出: 3
注意:

给定数组的长度不会超过50000。
输入数组中的所有数字都在32位整数的表示范围内。
 * .
 */

class BIT
{
private:
    vector<int> datas;
    size_t n;

public:
    BIT(size_t count) : datas(count + 1, 0), n(count)
    {
    }

    static int lowbit(int x)
    {
        return x & (-x);
    }

    void update(int x, int delta)
    {
        while (x <= n)
        {
            datas.at(x) += delta;
            x += lowbit(x);
        }
    }

    int query(int x)
    {
        int res = 0;

        while (x)
        {
            res += datas.at(x);
            x -= lowbit(x);
        }

        return res;
    }
};

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        set<long long> vSet;
        for (auto &it : nums)
        {
            vSet.insert((long long)it);
            vSet.insert(2 * (long long)it);
        }

        int idx = 1;
        unordered_map<long long, int> dicts;
        for (auto &it : vSet)
        {
            dicts[it] = idx++;
        }

        int res = 0;
        BIT bit(dicts.size());
        for (size_t i = 0; i < nums.size(); i++)
        {
            long long target = 2LL * nums.at(i);

            int d = dicts[target];
            res += bit.query(dicts.size()) - bit.query(d);
            bit.update(dicts[nums.at(i)], 1);
        }

        return res;
    }
};
