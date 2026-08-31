# []

> **原题链接:** (https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>

using namespace std;

// KMP算法模版
// 测试链接 : https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
class Solution {
public:
    int strStr(string s1, string s2) {
        // return s1.indexOf(s2);
        vector<char> a(s1.begin(), s1.end());
        vector<char> b(s2.begin(), s2.end());
        return kmp(a, b);
    }

    // KMP算法
    int kmp(const vector<char>& s1, const vector<char>& s2) {
        // s1中当前比对的位置是x
        // s2中当前比对的位置是y
        int n = s1.size();
        int m = s2.size();
        int x = 0;
        int y = 0;
        // O(m)
        vector<int> next = nextArray(s2, m);
        // O(n)
        while (x < n && y < m) {
            if (s1[x] == s2[y]) {
                x++;
                y++;
            } else if (y == 0) {
                x++;
            } else {
                y = next[y];
            }
        }
        return y == m ? x - y : -1;
    }

    // 得到next数组
    vector<int> nextArray(const vector<char>& s, int m) {
        if (m == 1) {
            return {-1};
        }
        vector<int> next(m);
        next[0] = -1;
        next[1] = 0;
        // i表示当前要求next值的位置
        // cn表示当前要和前一个字符比对的下标
        int i = 2;
        int cn = 0;
        while (i < m) {
            if (s[i - 1] == s[cn]) {
                next[i++] = ++cn;
            } else if (cn > 0) {
                cn = next[cn];
            } else {
                next[i++] = 0;
            }
        }
        return next;
    }
};
```

---

