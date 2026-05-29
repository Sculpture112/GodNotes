# [078 Code07 路径总和 III]

> **原题链接:** (https://leetcode.cn/problems/path-sum-iii/)

**题目简介:** 给定一棵二叉树和目标值 `targetSum`，统计树中有多少条向下路径的节点和恰好等于目标值。路径不要求从根开始，也不要求到叶子结束。

**涉及知识点:** [[前缀和]], [[树形递归]]，[[待补题]],[[]],[[]]

**核心套路:** 在树上维护“从根递归到当前节点的前缀和”，并用哈希表统计每种前缀和出现次数。到达当前节点时，查找 `sum - target` 出现了多少次即可。

## 破题切入点 (思维闪念)
[数组里的“前缀和 + 哈希表”可以直接搬到树上，只不过这里前缀和是沿着递归路径动态维护的。]



```cpp
// 078 Code07 路径总和 III

// 给定一个二叉树的根节点root，和一个整数targetSum
// 求该二叉树里节点值之和等于targetSum的路径的数目
// 路径不需要从根节点开始，也不需要在叶子节点结束
// 但是路径方向必须是向下的(只能从父节点到子节点)
// 测试链接 : https://leetcode.cn/problems/path-sum-iii/

#include <unordered_map>

using namespace std;

class Code07_PathSumIII {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
    };

    static int ans;

    static int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> presum;
        presum[0] = 1;
        ans = 0;
        f(root, targetSum, 0, presum);
        return ans;
    }

    static void f(TreeNode* x, int target, long long sum, unordered_map<long long, int>& presum) {
        if (x != nullptr) {
            sum += x->val;
            auto it = presum.find(sum - target);
            if (it != presum.end()) {
                ans += it->second;
            }
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
