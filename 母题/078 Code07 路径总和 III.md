# [078 Code07 路径总和 III]

> **原题链接:** (https://leetcode.cn/problems/path-sum-iii/)

**涉及知识点:** [[已AC]], [[树上dp]]，null,[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>

using namespace std;

// 路径总和 III
// 给定一个二叉树的根节点 root ，和一个整数 targetSum
// 求该二叉树里节点值之和等于 targetSum 的 路径 的数目
// 路径 不需要从根节点开始，也不需要在叶子节点结束
// 但是路径方向必须是向下的（只能从父节点到子节点）
// 测试链接 : https://leetcode.cn/problems/path-sum-iii/
class Code07_PathSumIII {
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
    static int pathSum(TreeNode* root, int sum) {
        unordered_map<long long, int> presum;
        presum[0] = 1;
        ans = 0;
        f(root, sum, 0, presum);
        return ans;
    }

    static int ans;

    // sum : 从头节点出发，来到x的时候，上方累加和是多少
    // 路径必须以x作为结尾，路径累加和是target的路径数量，累加到全局变量ans上
    static void f(TreeNode* x, int target, long long sum, unordered_map<long long, int>& presum) {
        if (x != nullptr) {
            sum += x->val; // 从头节点出发一路走到x的整体累加和
            ans += presum.count(sum - target) ? presum[sum - target] : 0;
            presum[sum]++;
            f(x->left, target, sum, presum);
            f(x->right, target, sum, presum);
            presum[sum]--;
        }
    }
};

int Code07_PathSumIII::ans = 0;
```

---
