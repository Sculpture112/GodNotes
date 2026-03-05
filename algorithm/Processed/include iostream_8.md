# include <iostream>

```cpp
# P3799 小 Y 拼木棒## 题目背景上道题中，小 Y 斩了一地的木棒，现在她想要将木棒拼起来。## 题目描述有 $n$ 根木棒，现在从中选 $4$ 根，想要组成一个正三角形，问有几种选法？答案对 $10^9+7$ 取模。## 输入格式第一行一个整数 $n$。第二行往下 $n$ 行，每行 $1$ 个整数，第 $i$ 个整数 $a_i$ 代表第 $i$ 根木棒的长度。## 输出格式一行一个整数代表答案。## 输入输出样例 #1### 输入 #1```4 1122```### 输出 #1```1```## 说明/提示#### 数据规模与约定- 对于 $30\%$ 的数据，保证 $n \le 5 \times 10^3$。- 对于 $100\%$ 的数据，保证 $1 \leq n \le 10^5$，$1 \le a_i \le 5 \times 10^3$。关于标题：因为一些不可抗力的原因，名称进行了更改。深表歉意。

#include <iostream>
#include <vector>

using namespace std;

long long cnt[5005];
const int MOD = 1e9 + 7;

int main() {
    int n, max_len = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cnt[a]++;
        max_len = max(max_len, a);
    }

    long long ans = 0;
    // 枚举正三角形的边长 i
    for (int i = 2; i <= max_len; ++i) {
        if (cnt[i] < 2) continue;

        // C(cnt[i], 2)
        long long ways_to_pick_two_sides = cnt[i] * (cnt[i] - 1) / 2 % MOD;

        // 枚举组成第三边的两根木棒，长度分别为 j 和 i-j
        // 为了不重复计算，j 只需要枚举到 i/2
        for (int j = 1; j <= i / 2; ++j) {
            int k = i - j;
            if (cnt[j] == 0 || cnt[k] == 0) continue;

            if (j != k) {
                // 两根长度不等：cnt[j] * cnt[k]
                ans = (ans + ways_to_pick_two_sides * cnt[j] % MOD * cnt[k] % MOD) % MOD;
            } else if (cnt[j] >= 2) {
                // 两根长度相等：C(cnt[j], 2)
                long long ways_to_pick_third_side = cnt[j] * (cnt[j] - 1) / 2 % MOD;
                ans = (ans + ways_to_pick_two_sides * ways_to_pick_third_side % MOD) % MOD;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
```
