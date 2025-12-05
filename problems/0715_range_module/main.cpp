#include "solution.hpp"
#include <iostream>

int main()
{
    RangeModule rm;
    rm.addRange(10, 20);
    rm.removeRange(14, 16);
    std::cout << std::boolalpha << rm.queryRange(10, 14) << std::endl; // true
    std::cout << std::boolalpha << rm.queryRange(13, 15) << std::endl; // false
    std::cout << std::boolalpha << rm.queryRange(16, 17) << std::endl; // true
    return 0;
}
