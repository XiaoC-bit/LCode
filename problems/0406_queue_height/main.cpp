#include "solution.hpp"
#include <iostream>

int main()
{
    Solution s;
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    s.reconstructQueue(people);
    return 0;
}
