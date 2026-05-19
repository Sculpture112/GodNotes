# []

> **原题链接:** (https://codeforces.com/contest/2230/problem/B)

**涉及知识点:** [[]], [[]]，[[待补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]


解法一：统计前缀，然后边遍历边统计

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve1() {
    string s;
    cin >> s;
    
    int cnt4 = 0;
    string clean_s = "";
    
    // 重点：先把所有的 4 找出来并“删掉”
    for (char c : s) {
        if (c == '4') cnt4++;
        else clean_s += c; // 剩下的只有 1, 2, 3
    }
    
    // 统计干净字符串中，总共有多少个 1 和 3
    int total_13 = 0;
    for (char c : clean_s) {
        if (c == '1' || c == '3') total_13++;
    }
    
    // max_keep 记录我们最多能保留多少个字符
    int max_keep = total_13; // 极端情况：全部保留 1 和 3，把 2 全删了
    int current_2 = 0;       // 遍历时记录当前遇到了多少个 2
    int current_13 = 0;      // 遍历时记录当前遇到了多少个 1 和 3
    
    for (char c : clean_s) {
        if (c == '2') {
            current_2++;
        } else {
            current_13++;
        }
        // 对于当前位置，左边保留所有的 2（current_2），右边保留所有的 1和3 (total_13 - current_13)
        max_keep = max(max_keep, current_2 + (total_13 - current_13));
    }
    
    // 总长度 减去 最多能保留的长度，就是需要删除的最小次数，再加上必定要删的 4 的数量
    cout << cnt4 + ((int)clean_s.length() - max_keep) << "\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve1();
    }
    return 0;
}
```

解法二：状态机dp

```c++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve2() {
    string s;
    cin >> s;
    
    int dp0 = 0; // 最长合法序列：末尾是 2 (纯 2 序列)
    int dp1 = 0; // 最长合法序列：末尾是 1 或 3 (形式为 22..213..3)
    
    for (char c : s) {
        if (c == '2') {
            // '2' 只能加在纯 '2' 的队伍后面
            dp0++; 
        } 
        else if (c == '1' || c == '3') {
            // '1' 和 '3' 可以接在 纯'2' 后面，也可以接在已经有 '1'/'3' 的后面
            dp1 = max(dp0, dp1) + 1;
        }
        // 如果是 '4'，直接跳过，任何合法序列的长度都不会增加
    }
    
    // max(dp0, dp1) 是我们能在原字符串中找到的最长的合法子序列长度
    int max_keep = max(dp0, dp1);
    
    // 原字符串总长度 减去 能保留的最长合法长度，即为最少需要删除的字符数
    cout << s.length() - max_keep << "\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve2();
    }
    return 0;
}
```
---


