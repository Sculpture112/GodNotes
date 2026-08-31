# []

> **原题链接:** (https://www.luogu.com.cn/problem/P3375)

**涉及知识点:** [[KMP]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

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

    string s1, s2;
    cin >> s1 >> s2;

    // 改成 1 下标，便于书写 KMP
    s1 = " " + s1;
    s2 = " " + s2;

    int n = static_cast<int>(s1.size()) - 1;
    int m = static_cast<int>(s2.size()) - 1;

    vector<int> nxt(m + 1, 0);

    // 构造模式串 s2 的 next 数组
    for (int i = 2, j = 0; i <= m; ++i) {
        while (j > 0 && s2[i] != s2[j + 1]) {
            j = nxt[j];
        }

        if (s2[i] == s2[j + 1]) {
            ++j;
        }

        nxt[i] = j;
    }

    // 在主串 s1 中匹配模式串 s2
    for (int i = 1, j = 0; i <= n; ++i) {
        while (j > 0 && s1[i] != s2[j + 1]) {
            j = nxt[j];
        }

        if (s1[i] == s2[j + 1]) {
            ++j;
        }

        if (j == m) {
            cout << i - m + 1 << '\n';

            // 继续寻找下一个匹配，也能处理重叠匹配
            j = nxt[j];
        }
    }

    // 输出 s2 每个前缀的最长 border 长度
    for (int i = 1; i <= m; ++i) {
        cout << nxt[i] << (i == m ? '\n' : ' ');
    }

    return 0;
}
```

---


