# []

> **原题链接:** ()

**涉及知识点:** [[数学]], [[状态压缩]]，[[补题]],[[构造]],[[贪心算法]]

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


