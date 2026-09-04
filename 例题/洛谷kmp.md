# []

> **原题链接:** (https://www.luogu.com.cn/problem/P3375)

**涉及知识点:** [[KMP]], [[0]]，[[补题]],[[]],[[]]

**核心套路:** 
[[2026-09-04-10-52-05]]
## 破题切入点 (思维闪念)
[]



```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    cin >> text >> pattern;

    // 改成 1 下标，便于使用 pattern[j + 1]
    text = " " + text;
    pattern = " " + pattern;

    int n = static_cast<int>(text.size()) - 1;
    int m = static_cast<int>(pattern.size()) - 1;

    vector<int> nxt(m + 1, 0);

    // 计算模式串的 nxt 数组
    for (int i = 2, j = 0; i <= m; ++i) {
        // 当前候选无法接上 pattern[i]，回退到更短候选
        while (j > 0 && pattern[i] != pattern[j + 1]) {
            j = nxt[j];
        }

        // 如果能接上，公共前后缀长度增加 1
        if (pattern[i] == pattern[j + 1]) {
            ++j;
        }

        nxt[i] = j;
    }

    // 使用 KMP 在主串中匹配模式串
    for (int i = 1, j = 0; i <= n; ++i) {
        // 主串当前位置不动，模式串匹配长度回退
        while (j > 0 && text[i] != pattern[j + 1]) {
            j = nxt[j];
        }

        // 当前字符匹配成功
        if (text[i] == pattern[j + 1]) {
            ++j;
        }

        // 模式串完整匹配
        if (j == m) {
            cout << i - m + 1 << '\n';

            // 保留可能重叠的部分，继续匹配
            j = nxt[j];
        }
    }

    // 输出每个前缀的最长 border 长度
    for (int i = 1; i <= m; ++i) {
        if (i > 1) {
            cout << ' ';
        }
        cout << nxt[i];
    }
    cout << '\n';

    return 0;
}
```

---


