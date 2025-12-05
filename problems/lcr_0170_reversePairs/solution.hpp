#pragma once
#include "../../include/utils.h"

class BIT
{
private:
    vector<int> trees;
    size_t n_;

public:
    BIT(size_t n) : n_(n), trees(n + 1, 0) {
                    };
    ~BIT() {
    };

    static int lowBit(int x)
    {
        return x & (-x);
    }

    void update(int x, int delta)
    {
        while (x <= n_)
        {
            trees[x] += delta;
            x += lowBit(x);
        }
    }

    int query(int x)
    {
        int count = 0;
        while (x > 0)
        {
            count += trees[x];
            x -= lowBit(x);
        }
        return count;
    }

private:
};

class Solution
{
public:
    int reversePairs(vector<int> &record)
    {
        int ans = 0;

        vector<int> tmp = record;
        sort(tmp.begin(), tmp.end());

        for (int &num : record)
        {
            // num =( lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin() )  + 1;
            num = static_cast<int>(lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin()) + 1;
        }

        BIT bit(record.size() + 1);

        for (size_t i = record.size() - 1; i >= 0; i--)
        {
            ans += bit.query(record.at(i) - 1);
            bit.update(record.at(i), 1);
        }

        return ans;
    }
};