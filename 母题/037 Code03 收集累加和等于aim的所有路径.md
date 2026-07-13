# []

> **原题链接:** (https://leetcode.cn/problems/path-sum-ii/)

**涉及知识点:** [[]], [[]]，[[]],[[]],[[]]

**核心套路:** 

## 破题切入点(思维闪念)
[]

```cpp
#include <bits/stdc++.h>

using namespace std;

// 收集累加和等于aim的所有路径
// 测试链接 : https://leetcode.cn/problems/path-sum-ii/
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int aim) {
        vector<vector<int>> ans;
        if (root != nullptr) {
            vector<int> path;
            f(root, aim, 0, path, ans);
        }
        return ans;
    }

    void f(TreeNode* cur, int aim, int sum, vector<int>& path, vector<vector<int>>& ans) {
        if (cur->left == nullptr && cur->right == nullptr) {
            // 叶节点
            if (cur->val + sum == aim) {
                path.push_back(cur->val);
                copy(path, ans);
                path.pop_back();
            }
        } else {
            // 不是叶节点
            path.push_back(cur->val);
            if (cur->left != nullptr) f(cur->left, aim, sum + cur->val, path, ans);
            if (cur->right != nullptr) f(cur->right, aim, sum + cur->val, path, ans);
            path.pop_back();
        }
    }

    void copy(vector<int>& path, vector<vector<int>>& ans) {
        vector<int> copy;
        for (int num : path) copy.push_back(num);
        ans.push_back(copy);
    }
};
```

---

