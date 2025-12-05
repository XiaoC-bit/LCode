#include "solution.hpp"
#include <iostream>

int main()
{
    Solution s;
    auto res = s.generateParenthesis(3);
    for (const auto &str : res)
    {
        std::cout << str << std::endl;
    }

    return 0;
}
