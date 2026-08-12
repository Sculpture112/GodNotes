# []

> **原题链接:** ()

**涉及知识点:** [[数学]], [[状态压缩]]，[[补题]],[[构造]],[[贪心算法]],[[贡献法]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    ll x, y;
    cin >> x >> y;

    ll bestDist = LINF;
    int bestN = 0;
    ll bestP = 0;

    for (int n = 1;; n++) {
        ll sum = 1LL * n * (n + 1) / 2;
        if (sum > x + y) break;

        // p <= x，并且 q = sum - p <= y
        ll left = max(0LL, sum - y);
        ll right = min(sum, x);

        // 固定 p + q = sum 时：
        // (x-p)^2 + (y-q)^2
        // 的实数最优点为 p = (sum+x-y)/2
        ll center = sum + x - y;
        ll p1 = center / 2;
        ll p2 = p1 + 1;

        for (ll p : {p1, p2}) {
            p = clamp(p, left, right);
            ll q = sum - p;

            ll dist = (x - p) * (x - p)
                    + (y - q) * (y - q);

            if (dist < bestDist) {
                bestDist = dist;
                bestN = n;
                bestP = p;
            }
        }
    }

    string ans(bestN, 'Y');
    ll need = bestP;

    // 第 i 次操作对最终坐标的贡献为 bestN-i+1。
    // 因此只需从 1..bestN 中选出若干数，使其和为 bestP。
    for (int weight = bestN; weight >= 1; weight--) {
        if (need >= weight) {
            need -= weight;
            int position = bestN - weight;
            ans[position] = 'X';
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
```

---


D. Hypercarp 与跨维跳跃

每个测试点时间限制：2 秒  
每个测试点内存限制：512 MB

Hypercarp 正驾驶宇宙飞船在二维银河地图中旅行。飞船初始位于点 `(0, 0)`，他想抵达的空间站位于点 `(x, y)`。

Hypercarp 的飞船配备了一台实验性的跨维引擎。引擎当前状态由跳跃向量 `(a, b)` 描述：每当引擎启动时，飞船会在第一维坐标移动 `a` 个单位，在第二维坐标移动 `b` 个单位。初始时，引擎完全没有能量，因此 `(a, b) = (0, 0)`。

引擎按连续的周期工作，每个周期称为一次移动。在一次移动中，依次执行：

- 引擎积蓄能量，Hypercarp 必须恰好将 `a` 或 `b` 中的一个增加 `1`；
- 飞船进行一次跨维跳跃，从点 `(p, q)` 移动到 `(p + a, q + b)`。

`a` 和 `b` 的值不能减少。

Hypercarp 与空间站之间存在一条安全的跨维走廊，它表示为矩形 `[0, x] × [0, y]`。如果飞船在任意一次跳跃后离开该矩形，就会进入不稳定空间并被摧毁。

Hypercarp 可以在任意次跳跃后结束旅程。由于不一定能恰好到达空间站，他希望停在一个合法点上，并使其尽可能接近 `(x, y)`。

请帮助 Hypercarp 选择移动次数，以及每次移动时增加哪个引擎参数，使飞船最终停在合法点 `(p, q)`，且其到空间站的欧几里得距离平方最小。即最小化：

```
(p - x)^2 + (q - y)^2
```

**输入**

每个输入包含多组测试数据。第一行包含测试用例数量 `t`（`1 ≤ t ≤ 100`）。

每组测试数据仅包含一行，含两个整数 `x` 和 `y`（`1 ≤ x, y ≤ 10^8`），表示 Hypercarp 想到达的空间站坐标。

**输出**

对于每个测试用例，输出一个仅由字符 `X` 和 `Y` 组成的字符串 `s`，表示 Hypercarp 的一条最优旅程。

字符串 `s` 的长度等于移动次数。字符 `s[i]` 表示第 `i` 次移动中的操作：

- 若 `s[i] = X`，Hypercarp 将 `a` 增加 `1`，然后使用新的向量进行跳跃；
- 若 `s[i] = Y`，Hypercarp 将 `b` 增加 `1`，然后使用新的向量进行跳跃。

该字符串描述的旅程必须满足题目的所有条件，且最终到达的点到空间站的距离平方最小。

可以证明，在题目限制下，任意最优答案至多包含 `20000` 次跳跃。若存在多个最优答案，输出任意一个即可。

**样例**

输入：

```
7
1 1
2 1
4 2
5 4
3 7
1 100
231 157
```

输出：

```
Y
XY
XYX
XYY
YXYY
YYYYYYYYYYYYY
XXXXXXXXXXYYYYYYYYYYYYYYYYX
```

**说明**

考虑部分测试用例：

第一组中，字符串 `X` 表示进行一次移动。Hypercarp 将 `a` 增加 `1`，随后完成跳跃：

```
(0, 0) -> (1, 0)
```

到空间站 `(1, 1)` 的距离平方为 `1`。

第二组中，字符串 `XY` 能使飞船恰好到达空间站：

```
(0, 0) -> (1, 0) -> (2, 1)
```

第三组中，字符串 `XYX` 对应以下跳跃过程：

```
(0, 0) -> (1, 0) -> (2, 1) -> (4, 2)
```

因此飞船恰好到达空间站 `(4, 2)`。

第四组中，字符串 `XYY` 会使飞船到达 `(3, 3)`。它到空间站 `(5, 4)` 的距离平方为：

```
(3 - 5)^2 + (3 - 4)^2 = 5
```

另一个最优答案是 `XYX`，它会使飞船到达 `(4, 2)`。