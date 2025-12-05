#include "solution.hpp"
#include <iostream>

int main()
{
    Solution s;
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = s.trap(nums);
    cout << result << endl;
    return 0;
}
