# []

> **原题链接:** (https://codeforces.com/gym/106144/problem/M)

**涉及知识点:** [[字符串]], [[]]，[[待补题]],[[]],[[]]
字符串find的用法，很简单的一道题
**核心套路:** 


```cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        // 统计所有 '1' 的个数
        int count1 = count(s.begin(), s.end(), '1');

        // 优先检查是否有连续 3 个 1
        if (s.find("111") != string::npos) {
            cout << count1 - 2 << "\n";
        }
        // 其次检查是否有连续 2 个 1
        else if (s.find("11") != string::npos) {
            cout << count1 - 1 << "\n";
        }
        // 都没有，则火球术无法带来额外收益，一律只能一个个打
        else {
            cout << count1 << "\n";
        }
    }
}

int main() {
    // 优化输入输出流
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
```

---

解法2
```c++
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int total_ones = 0;   // 记录总共的 1
        int max_len = 0;      // 记录最长连续 1 的长度
        int current_len = 0;  // 当前连续 1 的长度

        for (char c : s) {
            if (c == '1') {
                total_ones++;
                current_len++;
                max_len = max(max_len, current_len);
            } else {
                current_len = 0; // 遇到 0，连续状态中断，长度清零
            }
        }

        // 根据最大连续长度决定能省多少步
        if (max_len >= 3) {
            cout << total_ones - 2 << "\n";
        } else if (max_len == 2) {
            cout << total_ones - 1 << "\n";
        } else {
            cout << total_ones << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
```
