# [078 Code01 最大BST子树]

> **原题链接:** (https://leetcode.cn/problems/largest-bst-subtree/)

**题目简介:** 给定一棵二叉树，求其中节点数最多的二叉搜索子树，并返回这棵最大 BST 子树的大小。

**涉及知识点:** [[树形DP]], [[后序遍历]]，[[待补题]],[[]],[[]]

**核心套路:** 每个节点向上返回四类信息：当前子树最大值、最小值、是否为 BST、以及当前子树内最大 BST 的大小。父节点据此一次整合。

## 破题切入点 (思维闪念)
[树上的“整棵子树是否合法 + 最优答案”很适合后序递归，让左右子树先把信息算完，再由当前节点统一判断。]



```cpp
// 078 Code01 最大BST子树

// 给定一个二叉树，找到其中最大的二叉搜索树(BST)子树，并返回该子树的大小
// 其中，最大指的是子树节点数最多的
// 二叉搜索树(BST)中的所有节点都具备以下属性：
// 左子树的值小于其父(根)节点的值
// 右子树的值大于其父(根)节点的值
// 注意：子树必须包含其所有后代
// 测试链接 : https://leetcode.cn/problems/largest-bst-subtree/

#include <algorithm>
#include <climits>

using namespace std;

class Code01_LargestBstSubtree {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
    };

    struct Info {
        long long mx;
        long long mn;
        bool isBst;
        int maxBstSize;

        Info(long long a, long long b, bool c, int d) : mx(a), mn(b), isBst(c), maxBstSize(d) {}
    };

    static int largestBSTSubtree(TreeNode* root) {
        return f(root).maxBstSize;
    }

    static Info f(TreeNode* x) {
        if (x == nullptr) {
            return Info(LLONG_MIN, LLONG_MAX, true, 0);
        }
        Info infol = f(x->left);
        Info infor = f(x->right);
        long long mx = max(static_cast<long long>(x->val), max(infol.mx, infor.mx));
        long long mn = min(static_cast<long long>(x->val), min(infol.mn, infor.mn));
        bool isBst = infol.isBst && infor.isBst && infol.mx < x->val && x->val < infor.mn;
        int maxBstSize = isBst ? (infol.maxBstSize + infor.maxBstSize + 1)
                               : max(infol.maxBstSize, infor.maxBstSize);
        return Info(mx, mn, isBst, maxBstSize);
    }
};
```

---
