#pragma once
#include "../../include/utils.h"

class Solution
{

public:
private:
    struct Data
    {
        int height;
        int orgK;
        int curK;
    };

    void findFirst(vector<Data> &people)
    {
        sort(people.begin(), people.end(), [](const Data &a, const Data &b)
             {
                 if (a.curK == b.curK)
                 {
                     return a.height < b.height;
                 }
                 return a.curK < b.curK;
             });
        auto first = people.at(0);
        for (auto it = people.begin(); it != people.end(); it++)
        {
            if (it == people.begin())
                continue;
            if (first.height >= it->height)
            {
                it->curK--;
            }
        }
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {

        vector<Data> datas;
        for (auto &p : people)
        {
            Data data;
            data.height = p[0];
            data.orgK = p[1];
            data.curK = p[1];
            datas.push_back(data);
        }

        vector<vector<int>> res;
        while (datas.size())
        {
            findFirst(datas);

            vector<int> tmp(2);
            tmp[0] = datas.at(0).height;
            tmp[1] = datas.at(0).orgK;

            datas.erase(datas.begin());
            res.push_back(tmp);
        }

        return res;
    }
};
