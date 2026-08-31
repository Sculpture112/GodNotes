# []

> **原题链接:** (https://www.luogu.com.cn/problem/P3805)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>

using namespace std;

// Manacher算法模版
// 求字符串s中最长回文子串的长度
// 测试链接 : https://www.luogu.com.cn/problem/P3805
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过

const int MAXN = 11000001;

char ss[MAXN << 1];
int p[MAXN << 1];
int n;

void manacherss(const string& a) {
    n = a.length() * 2 + 1;
    for (int i = 0, j = 0; i < n; i++) {
        ss[i] = (i & 1) == 0 ? '#' : a[j++];
    }
}

int manacher(const string& str) {
    manacherss(str);
    int maxValue = 0;
    for (int i = 0, c = 0, r = 0, len; i < n; i++) {
        len = r > i ? min(p[2 * c - i], r - i) : 1;
        while (i + len < n && i - len >= 0 && ss[i + len] == ss[i - len]) {
            len++;
        }
        if (i + len > r) {
            r = i + len;
            c = i;
        }
        maxValue = max(maxValue, len);
        p[i] = len;
    }
    return maxValue - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    cout << manacher(str) << '\n';
    return 0;
}
```

---

