# [098 Code07 学生出勤记录II]

> **原题链接:** (https://leetcode.cn/problems/student-attendance-record-ii/)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

// 学生出勤记录II
// 可以用字符串表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）
// 记录中只含下面三种字符：
// 'A'：Absent，缺勤
// 'L'：Late，迟到
// 'P'：Present，到场
// 如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励：
// 按 总出勤 计，学生缺勤（'A'）严格 少于两天
// 学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。
// 给你一个整数n，表示出勤记录的长度（次数）
// 请你返回记录长度为n时，可能获得出勤奖励的记录情况数量
// 答案可能很大，结果对1000000007取模
// 测试链接 : https://leetcode.cn/problems/student-attendance-record-ii/
class Solution {
public:
    const int MOD = 1000000007;

    int checkRecord(int n) {
        vector<vector<int>> start = {{1, 1, 0, 1, 0, 0}};
        vector<vector<int>> base = {
            {1, 1, 0, 1, 0, 0},
            {1, 0, 1, 1, 0, 0},
            {1, 0, 0, 1, 0, 0},
            {0, 0, 0, 1, 1, 0},
            {0, 0, 0, 1, 0, 1},
            {0, 0, 0, 1, 0, 0}
        };
        vector<vector<int>> ans = multiply(start, power(base, n - 1));
        int ret = 0;
        for (int x : ans[0]) {
            ret = (ret + x) % MOD;
        }
        return ret;
    }

    vector<vector<int>> multiply(const vector<vector<int>>& a, const vector<vector<int>>& b) {
        int n = a.size();
        int m = b[0].size();
        int k = a[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int c = 0; c < k; c++) {
                    ans[i][j] = ((long long)a[i][c] * b[c][j] + ans[i][j]) % MOD;
                }
            }
        }
        return ans;
    }

    vector<vector<int>> power(vector<vector<int>> m, int p) {
        int n = m.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            ans[i][i] = 1;
        }
        while (p != 0) {
            if ((p & 1) != 0) {
                ans = multiply(ans, m);
            }
            m = multiply(m, m);
            p >>= 1;
        }
        return ans;
    }
};
```

---

