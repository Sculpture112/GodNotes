# []

> **原题链接:** (https://atcoder.jp/contests/abc461/tasks/abc461_c?lang=en)

**涉及知识点:** [[贪心]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, M;
    cin >> N >> K >> M;

    vector<pair<ll, int>> gems; // {value, color}
    for (int i = 0; i < N; i++) {
        int C;
        ll V;
        cin >> C >> V;
        gems.push_back({V, C});
    }

    sort(gems.rbegin(), gems.rend());

    vector<int> cnt(N + 1, 0);
    vector<ll> removable; // 已选中、重复颜色的宝石价值
    vector<ll> addable;   // 未选中、能带来新颜色的宝石价值

    ll ans = 0;
    int colors = 0;

    // 先选价值最大的 K 颗
    for (int i = 0; i < K; i++) {
        auto [v, c] = gems[i];
        ans += v;

        cnt[c]++;
        if (cnt[c] == 1) {
            colors++;
        } else {
            removable.push_back(v);
        }
    }

    // 收集未选中、颜色还没出现过的宝石
    for (int i = K; i < N; i++) {
        auto [v, c] = gems[i];

        if (cnt[c] == 0) {
            addable.push_back(v);
            cnt[c] = -1; // 标记这个颜色已经收集过一个候选
        }
    }

    sort(removable.begin(), removable.end()); // 从小到大删
    sort(addable.rbegin(), addable.rend());   // 从大到小加

    int i = 0, j = 0;

    while (colors < M) {
        ans -= removable[i];
        ans += addable[j];

        i++;
        j++;
        colors++;
    }

    cout << ans << '\n';

    return 0;
}
```

---


