# [078 Code01 最大BST子树]

> **原题链接:** (https://leetcode.cn/problems/largest-bst-subtree/)

**涉及知识点:** [[已AC]], [[树上dp]]，null,[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>

using namespace std;

// 最大BST子树
// 给定一个二叉树，找到其中最大的二叉搜索树（BST）子树，并返回该子树的大小
// 其中，最大指的是子树节点数最多的
// 二叉搜索树（BST）中的所有节点都具备以下属性：
// 左子树的值小于其父（根）节点的值
// 右子树的值大于其父（根）节点的值
// 注意：子树必须包含其所有后代
// 测试链接 : https://leetcode.cn/problems/largest-bst-subtree/
class Code01_LargestBstSubtree {
public:
    // 不要提交这个结构
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
        TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
    };

    // 提交如下的方法
    static int largestBSTSubtree(TreeNode* root) {
        return f(root).maxBstSize;
    }

    struct Info {
        long long mx;
        long long mn;
        bool isBst;
        int maxBstSize;

        Info(long long a, long long b, bool c, int d) : mx(a), mn(b), isBst(c), maxBstSize(d) {}
    };

    static Info f(TreeNode* x) {
        if (x == nullptr) {
            return Info(LLONG_MIN, LLONG_MAX, true, 0);
        }
        Info infol = f(x->left);
        Info infor = f(x->right);
        // 左 4信息
        // 右 4信息
        // x 整合出4信息返回
        long long mx = max((long long)x->val, max(infol.mx, infor.mx));
        long long mn = min((long long)x->val, min(infol.mn, infor.mn));
        bool isBst = infol.isBst && infor.isBst && infol.mx < x->val && x->val < infor.mn;
        int maxBstSize;
        if (isBst) {
            maxBstSize = infol.maxBstSize + infor.maxBstSize + 1;
        } else {
            maxBstSize = max(infol.maxBstSize, infor.maxBstSize);
        }
        return Info(mx, mn, isBst, maxBstSize);
    }
};
```

---
