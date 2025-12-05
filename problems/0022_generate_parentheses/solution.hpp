#pragma once
#include "../../include/utils.h"

class Solution
{
public:
    /*
    数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。



    示例 1：

    输入：n = 3
    输出：["((()))","(()())","(())()","()(())","()()()"]
    示例 2：

    输入：n = 1
    输出：["()"]


    输入：n = 2
    输出：["()()","(())"]

    提示：

    1 <= n <= 8

    */
    vector<string> generateParenthesis(int n);

private:
    // 动态规划解法
    vector<string> dp(int n);
    // 栈回溯法
    vector<string> stackbackTrace(int n);
    // 递归回溯法

    void recursizebackTrace(vector<string> &ans, string &cur, int open, int close, int n);
};
