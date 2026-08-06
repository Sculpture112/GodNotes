# []

> **原题链接:** ()

**涉及知识点:** [[线性基]], [[异或线性基]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll s = 0; // 整个数组的异或和
    for (ll &x : a) {
        cin >> x;
        s ^= x;
    }
    ll basis[61]{}; // basis[b] 保存最高位为第 b 位的线性基元素
    for (ll x : a) {
        x &= ~s; // 只保留 s 中为 0、能够优化的位置
        for (int b = 60; b >= 0; --b) {
            if (((x >> b) & 1) == 0) continue;
            if (basis[b] == 0) {
                basis[b] = x; // 当前最高位没有基底，保存 x
                break;
            }
            x ^= basis[b]; // 消掉当前最高位
        }
    }
    ll best = 0;
    for (int b = 60; b >= 0; --b) {
        best = max(best, best ^ basis[b]); // 求最大子集异或和
    }
    cout << s + 2 * best << '\n'; // s 是固定贡献，best 贡献两次
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
```

---


