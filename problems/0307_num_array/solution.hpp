#pragma once
#include "../../include/utils.h"

class BIT307
{
private:
    vector<int> datas;
    size_t n;

public:
    BIT307()
    {
    }

    static int lowbit(int x)
    {
        return x & (-x);
    }

    void init(size_t count)
    {
        datas = vector<int>(count + 1, 0);
        n = count;
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

    void update(int x, int data)
    {
        while (static_cast<size_t>(x) <= n)
        {
            datas.at(x) += data;
            x += lowbit(x);
        }
    }
};

class NumArray
{
private:
    vector<int> tree;
    int n;

    void build(vector<int> &nums, int node, int begin, int end)
    {
        if (begin == end)
        {
            tree[node] = nums.at(begin);
        }
        else
        {
            int mid = begin + (end - begin) / 2;
            build(nums, 2 * node, begin, mid);
            build(nums, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void updateTree(int node, int begin, int end, int idx, int val)
    {
        if (begin == end)
        {
            tree[node] = val;
        }
        else
        {
            int mid = begin + (end - begin) / 2;
            if (idx <= mid)
            {
                updateTree(2 * node, begin, mid, idx, val);
            }
            else
            {
                updateTree(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    int queryTree(int node, int begin, int end, int l, int r)
    {
        if (end < l || r < begin)
        {
            // 不在范围内
            return 0;
        }
        else if (l <= begin && end <= r)
        {
            return tree[node];
        }
        else
        {
            int mid = begin + (end - begin) / 2;

            int leftVal = queryTree(2 * node, begin, mid, l, r);
            int rightVal = queryTree(2 * node + 1, mid + 1, end, l, r);
            return leftVal + rightVal;
        }
    }

public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        tree.resize(4 * n);
        build(nums, 1, 0, n - 1);
    }

    void update(int index, int val)
    {
        updateTree(1, 0, n - 1, index, val);
    }

    int sumRange(int left, int right)
    {
        return queryTree(1, 0, n - 1, left, right);
    }
};
