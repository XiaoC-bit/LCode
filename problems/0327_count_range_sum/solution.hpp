#pragma once
#include "../../include/utils.h"

class BIT
{
private:
    vector<int> data;
    size_t n;

public:
    BIT(size_t num) : n(num), data(num + 1, 0)
    {
    }
    ~BIT()
    {
    }

    static int lowbit(int x)
    {
        return x & (-x);
    }

    int query(int x)
    {
        int res = 0;

        while (x)
        {
            res += data[x];
            x -= lowbit(x);
        }

        return res;
    }

    void update(int x, int delta)
    {
        while (static_cast<size_t>(x) <= n)
        {
            data[x] += delta;
            x += lowbit(x);
        }
    }
};

class Solution
{
public:
    int countRangeSum(vector<int> &nums, int lower, int upper)
    {

        // 先求前缀和
        vector<long long> preSum(nums.size() + 1, 0);
        long long sum = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            sum += nums.at(i);
            preSum[i + 1] = sum;
        }

        set<long long> values;
        for (auto &sum : preSum)
        {
            values.insert(sum);
            values.insert(sum - lower);
            values.insert(sum - upper);
        }

        int idx = 1;
        unordered_map<long long, int> formatMap;
        for (auto &value : values)
        {
            formatMap[value] = idx++;
        }

        BIT bit(formatMap.size());
        int res = 0;

        for (size_t i = 0; i <= nums.size(); i++)
        {
            long long x = preSum[i];
            long long L = x - upper;
            long long R = x - lower;

            res += bit.query(formatMap[R]) - bit.query(formatMap[L] - 1);
            bit.update(formatMap[x], 1);
        }

        return res;
    }
};
