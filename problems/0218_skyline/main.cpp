#include "solution.hpp"
#include <iostream>

int main()
{
    Solution s;
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    vector<vector<int>> skyline = s.getSkyline(buildings);
    for (const auto &point : skyline)
    {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;
    return 0;
}
