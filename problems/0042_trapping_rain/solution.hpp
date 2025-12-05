#pragma once
#include "../../include/utils.h"

class Solution
{

public:
    int trap(vector<int> &height)
    {
        stack<size_t> s;

        int res = 0;
        for (size_t i = 0; i < height.size(); i++)
        {

            // 栈为空，直接入栈
            if (s.empty())
            {
                s.push(i);
                continue;
            }

            size_t top = s.top();
            // 如果新元素小于等于栈顶元素，满足单调递减栈的条件，入栈
            if (height[i] <= height[top])
            {
                s.push(i);
                continue;
            }

            s.pop();
            if (s.empty())
            {
                s.push(i);
                continue;
            }
            size_t newTop = 0;
            while (s.size())
            {
                newTop = s.top();
                if (height[i] >= height[newTop])
                {
                    s.pop();
                }
                else
                {
                    break;
                }
            }
            int data = std::min(height[i], height[newTop]);
            for (size_t j = newTop + 1; j < i; j++)
            {
                res += data - height[j];
                height[j] = data; // 填满
            }
            s.push(i);
        }

        return res;
    }
};
