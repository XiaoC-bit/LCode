#include "solution.hpp"

#include <set>
#include <stack>

/*
 * 使用动态规划
 * 1.F(0) 和 F（1）是显而易见的，先设置初始解
 * 2.通过推断，得到公式  F(n) = "(" + F(p)  + ")" + F(q)
 *	其中p+q = n-1 .
 *	证明公式成立的难点是怎么证明以下等式成立时，p必然等于m && q必然等于n。如果无法证明，那么就需要使用set来过滤结果，这会增加时间复杂度
 *	"(" + F(p)  + ")" + F(q) = "(" + F(m)  + ")" + F(n)
 *	a.等式的左右两边，是独立的，也就是合法的括号表达式。
 *	b.F(q)可能是空，空的情况，容易得到F（n）也必须为空。那么F（p) = F(m)
 *	c.F(q)非空，由于加号两边必须是独立的表达式，也容易得到我们要的结果。
 *
 */
// 动态规划解法
vector<string> Solution::dp(int n)
{
    std::vector<std::vector<std::string>> dicts;

    vector<string> res;
    res.push_back("");
    dicts.push_back(res);

    res.clear();
    res.push_back("()");
    dicts.push_back(res);
    std::string str;
    for (size_t j = 2; j <= static_cast<size_t>(n); j++)
    {
        res.clear();
        for (size_t t = 0; t < j; t++)
        {
            auto dict1 = dicts[t];
            auto dict2 = dicts[j - t - 1];

            for (auto &s1 : dict1)
            {
                for (auto &s2 : dict2)
                {
                    str = "(" + s1 + ")" + s2;
                    res.push_back(str);
                }
            }
        }

        dicts.push_back(res);
    }

    return dicts.at(n);
}

/**
 * 栈回溯法性能是最好的.它避免了函数调用的栈开销
 *
 * \param n
 * \return
 */
vector<string> Solution::stackbackTrace(int n)
{

    struct Step
    {
        std::string str;
        int open;
        int close;

        Step()
        {
            str = "";
            open = close = 0;
        }
    };

    vector<string> res;

    if (n == 0)
    {
        res.push_back("");
        return res;
    }

    stack<Step> st;
    Step step;
    step.open = 1;
    step.str = "(";
    st.push(step);

    while (st.size())
    {
        auto step = st.top();
        st.pop();

        if (step.open < n)
        {
            auto newStep = step;
            newStep.open++;
            newStep.str += "(";
            st.push(newStep);
        }

        if (step.open > step.close)
        {
            auto newStep = step;
            newStep.close++;
            newStep.str += ")";
            if (newStep.str.size() == static_cast<size_t>(n) * 2)
            {
                res.push_back(newStep.str);
            }
            else
            {
                st.push(newStep);
            }
        }
    }

    return res;
}

/**
 * 递归回溯法，性能没有栈回溯好，但是易读性更好.
 *
 * \param ans
 * \param cur
 * \param open
 * \param close
 * \param n
 */
void Solution::recursizebackTrace(vector<string> &ans, string &cur, int open, int close, int n)
{
    if (cur.size() == static_cast<size_t>(n) * 2)
    {
        ans.push_back(cur);
        return;
    }
    if (open < n)
    {
        cur.push_back('(');
        recursizebackTrace(ans, cur, open + 1, close, n);
        cur.pop_back();
    }
    if (close < open)
    {
        cur.push_back(')');
        recursizebackTrace(ans, cur, open, close + 1, n);
        cur.pop_back();
    }
}

vector<string> Solution::generateParenthesis(int n)
{

    vector<string> result;
    string current;
    recursizebackTrace(result, current, 0, 0, n);
    return result;

    return stackbackTrace(n);

    return dp(n);
}
