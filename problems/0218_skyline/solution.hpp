#pragma once
#include "../../include/utils.h"

class Solution
{

public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        vector<vector<int>> ans;

        vector<pair<int, int>> datas;
        for (auto &b : buildings)
        {
            datas.push_back({b[0], -b[2]});
            datas.push_back({b[1], b[2]});
        }

        sort(datas.begin(), datas.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 if (a.first != b.first)
                 {
                     return a.first < b.first;
                 }

                 return a.second < b.second;
             });

        int curHeight = 0;
        multiset<int> heights;
        heights.insert(0);

        for (auto &d : datas)
        {
            if (d.second < 0)
            {
                heights.insert(-d.second);
            }
            else
            {
                heights.erase(heights.find(d.second));
            }

            int max = *heights.rbegin();
            if (max != curHeight)
            {
                ans.push_back({d.first, max});
                curHeight = max;
            }
        }

        return ans;
    }
};
