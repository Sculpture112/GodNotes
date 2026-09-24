# []

> **原题链接:** (https://codeforces.com/problemset/problem/1111/C)

**涉及知识点:** [[分治算法]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]

**触发条件：**

**关键观察/不变量：**

**最容易错的边界：**

**我第一次卡在哪里：**

**下次看到什么信号要想到它：**

**一个相似变式：**

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> pos;
ll A, B;

ll solve(ll l, ll r, int begin, int end) {
    ll count = end - begin;
    if (count == 0) return A;

    ll burn = B * count * (r - l + 1);
    if (l == r) return burn;

    ll mid = (l + r) / 2;
    int split = upper_bound(pos.begin() + begin, pos.begin() + end, mid)
              - pos.begin();

    ll divide = solve(l, mid, begin, split)
              + solve(mid + 1, r, split, end);

    return min(burn, divide);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k >> A >> B;

    pos.resize(k);
    for (int &x : pos) cin >> x;
    sort(pos.begin(), pos.end());

    cout << solve(1, 1LL << n, 0, k) << '\n';
    return 0;
}
```

---


