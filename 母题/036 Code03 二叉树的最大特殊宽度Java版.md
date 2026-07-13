# []

> **原题链接:** (https://leetcode.cn/problems/maximum-width-of-binary-tree/)

**涉及知识点:** [[]], [[]]，[[]],[[]],[[]]

**核心套路:** 

## 破题切入点(思维闪念)
[]

```cpp
#include <bits/stdc++.h>

using namespace std;

// 二叉树的最大特殊宽度，java版
// 测试链接 : https://leetcode.cn/problems/maximum-width-of-binary-tree/
class Solution {
public:
    // 提交以下的方法
    // 用每次处理一层的优化bfs就非常容易实现
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 1;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});
        while (!q.empty()) {
            int size = q.size();
            unsigned long long base = q.front().second;
            unsigned long long last = 0;
            for (int i = 0; i < size; i++) {
                auto [node, id] = q.front();
                q.pop();
                id -= base;
                last = id;
                if (node->left != nullptr) q.push({node->left, id * 2});
                if (node->right != nullptr) q.push({node->right, id * 2 + 1});
            }
            ans = max(ans, (int)(last + 1));
        }
        return ans;
    }
};
```

---

