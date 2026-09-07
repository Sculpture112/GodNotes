# []

> **原题链接:** (https://codeforces.com/contest/2238)

**涉及知识点:** [[gcd]], [[lcm]]，[[补题]],[[数论]],[[模型]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]

```md
核心思路：

题目要数三元组 (a, b, c)，满足：

gcd(lcm(a, b), lcm(b, c)) = gcd(a, c)

做法是按“质因子指数”分析。

设某个质因子 p 在 a, b, c 中的指数分别是 x, y, z。

因为：
gcd 对应指数取 min
lcm 对应指数取 max

所以原式对这个质因子变成：

min(max(x, y), max(y, z)) = min(x, z)

这个式子成立，当且仅当：

y <= min(x, z)

也就是说，b 中每个质因子的指数都不能超过 a 和 c 中对应指数的较小值。

翻译回整数就是：

b 整除 a，并且 b 整除 c。

所以题目条件等价于：

合法三元组 (a, b, c)
<=> b 整除 a 且 b 整除 c

接下来计数。

固定 b。

1 到 n 中，b 的倍数有：

floor(n / b)

个。

所以：
a 有 floor(n / b) 种选法
c 有 floor(n / b) 种选法

固定 b 的贡献是：

floor(n / b) * floor(n / b)

也就是：

floor(n / b)^2

最后让 b 从 1 枚举到 n，把所有贡献加起来：

ans = floor(n / 1)^2
    + floor(n / 2)^2
    + ...
    + floor(n / n)^2

代码核心：

long long ans = 0;

for (long long b = 1; b <= n; b++) {
    long long cnt = n / b;
    ans += cnt * cnt;
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long ans = 0;
        for (long long b = 1; b <= n; b++) {
            long long cnt = n / b;
            
            ans += cnt * cnt;
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---


