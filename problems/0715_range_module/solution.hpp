#pragma once
#include "../../include/utils.h"

/*


Range模块是跟踪数字范围的模块。设计一个数据结构来跟踪表示为 半开区间 的范围并查询它们。

半开区间 [left, right) 表示所有 left <= x < right 的实数 x 。

实现 RangeModule 类:

RangeModule() 初始化数据结构的对象。
void addRange(int left, int right)
添加 半开区间 [left, right)，
跟踪该区间中的每个实数。添加与当前跟踪的数字部分重叠的区间时，
应当添加在区间 [left, right) 中尚未跟踪的任何数字到该区间中。


boolean queryRange(int left, int right)
只有在当前正在跟踪区间 [left, right) 中的每一个实数时，
才返回 true ，否则返回 false 。


void removeRange(int left, int right)
停止跟踪 半开区间 [left, right)
中当前正在跟踪的每个实数。


示例 1：

输入
["RangeModule", "addRange", "removeRange", "queryRange", "queryRange", "queryRange"]
[[], [10, 20], [14, 16], [10, 14], [13, 15], [16, 17]]
输出
[null, null, null, true, false, true]

解释
RangeModule rangeModule = new RangeModule();
rangeModule.addRange(10, 20);
rangeModule.removeRange(14, 16);
rangeModule.queryRange(10, 14); 返回 true （区间 [10, 14) 中的每个数都正在被跟踪）
rangeModule.queryRange(13, 15); 返回 false（未跟踪区间 [13, 15) 中像 14, 14.03, 14.17 这样的数字）
rangeModule.queryRange(16, 17); 返回 true （尽管执行了删除操作，区间 [16, 17) 中的数字 16 仍然会被跟踪）

*/

class RangeModule
{
private:
    struct Node
    {
        Node *left;
        Node *right;
        int cover; // 1 = all covered, 0 = none, -1 = partial
        Node() : left(nullptr), right(nullptr), cover(0) {}
    };

    Node *root;
    static constexpr long long N = 20; // 1000000000LL; // domain [0, N)

    // 非递归释放整棵树（在析构中使用）
    void freeAll(Node *node)
    {
        if (!node)
            return;
        vector<Node *> stk;
        stk.push_back(node);
        while (!stk.empty())
        {
            Node *cur = stk.back();
            stk.pop_back();
            if (cur->left)
                stk.push_back(cur->left);
            if (cur->right)
                stk.push_back(cur->right);
            delete cur;
        }
    }

    // 将 node 的整段设置为 val（0/1），不删除子节点（仅设置 cover）
    inline void apply(Node *node, int val)
    {
        node->cover = val;
    }

    // 下推：若 node.cover 是确定值，则确保子节点存在并把值下推
    inline void push(Node *node)
    {
        if (!node)
            return;
        if (node->cover == -1)
            return; // 已是部分覆盖，不需下推确定值
        if (!node->left)
            node->left = new Node();
        if (!node->right)
            node->right = new Node();
        // 将确定值下推到子节点
        node->left->cover = node->cover;
        node->right->cover = node->cover;
        node->cover = -1;
    }

    // 更新区间 [ql, qr) 为 val（0 或 1）
    void update(Node *node, long long l, long long r, long long ql, long long qr, int val)
    {
        if (!node)
            return;
        if (ql >= r || qr <= l)
            return; // 无交集
        if (ql <= l && r <= qr)
        {
            apply(node, val);
            return;
        }
        // 部分相交
        push(node); // 如果父节点确定状态，下推给子节点（并把父改为 -1）
        long long mid = l + ((r - l) >> 1);
        if (ql < mid)
        {
            if (!node->left)
                node->left = new Node();
            update(node->left, l, mid, ql, qr, val);
        }
        if (qr > mid)
        {
            if (!node->right)
                node->right = new Node();
            update(node->right, mid, r, ql, qr, val);
        }
        // 合并子节点状态到父节点
        int leftCover = node->left ? node->left->cover : 0;
        int rightCover = node->right ? node->right->cover : 0;
        node->cover = (leftCover == rightCover) ? leftCover : -1;
    }

    // 查询区间 [ql, qr) 是否全部被覆盖；node 可能为 nullptr
    bool query(Node *node, long long l, long long r, long long ql, long long qr)
    {
        if (ql >= r || qr <= l)
            return true; // 空交集 -> 中性（认为已覆盖）
        if (!node)
            return false; // 未创建节点，且与查询区间有交集 -> 未覆盖
        if (ql <= l && r <= qr)
        {
            return node->cover == 1;
        }
        if (node->cover == 1)
            return true;
        if (node->cover == 0)
            return false;
        long long mid = l + ((r - l) >> 1);
        bool leftRes = query(node->left, l, mid, ql, qr);
        if (!leftRes)
            return false; // 早停
        bool rightRes = query(node->right, mid, r, ql, qr);
        return leftRes && rightRes;
    }

public:
    RangeModule()
    {
        root = new Node();
    }

    ~RangeModule()
    {
        freeAll(root);
        root = nullptr;
    }

    // 添加区间 [left, right)
    void addRange(int left, int right)
    {
        if (left >= right)
            return;
        update(root, 0, N, left, right, 1);
    }

    // 查询区间 [left, right) 是否完全被覆盖
    bool queryRange(int left, int right)
    {
        if (left >= right)
            return false;
        return query(root, 0, N, left, right);
    }

    // 移除区间 [left, right)
    void removeRange(int left, int right)
    {
        if (left >= right)
            return;
        update(root, 0, N, left, right, 0);
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 *
 *
 *
1 <= left < right <= 10^9
在单个测试用例中，对 addRange 、  queryRange 和 removeRange 的调用总数不超过 10^4 次
 *
 */
