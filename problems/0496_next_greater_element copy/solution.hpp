#pragma once
#include "../../include/utils.h"

class Solution
{
public:
    /*


    vector<int> nums1 = { 1,3,5,2,4 };
    vector<int>nums2 = { 6,5,4,3,2,1,7 };
    */
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        std::unordered_map<int, int> dicts;
        for (auto &it : nums1)
        {
            dicts[it] = -1;
        }
        stack<int> s;

        for (auto &it : nums2)
        {
            if (s.empty())
            {
                s.push(it);
                continue;
            }

            int top = s.top();
            if (top >= it)
            {
                s.push(it);
                continue;
            }

            s.pop();
            dicts[top] = it;

            while (s.size())
            {
                top = s.top();

                if (top >= it)
                {
                    break;
                }
                s.pop();
                dicts[top] = it;
            }
            s.push(it);
        }

        vector<int> ans;
        for (auto &it : nums1)
        {
            ans.push_back(dicts[it]);
        }

        return ans;
    }
};
