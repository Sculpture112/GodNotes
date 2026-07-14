# []

> **原题链接:** ()

**涉及知识点:** [[并查集]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> fa, sz;

    DSU(int n) : fa(n + 1), sz(n + 1, 1) {
        iota(fa.begin(), fa.end(), 0);
    }

    int find(int x) {
        if (fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;

        if (sz[x] < sz[y]) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> edges(m);
    for (auto &[u, v] : edges) {
        cin >> u >> v;
    }

    // 第 1 步：通过相等 a 值的边，把点合成零权连通块
    DSU dsu(n);
    for (auto [u, v] : edges) {
        if (a[u] == a[v]) {
            dsu.merge(u, v);
        }
    }

    // 第 2 步：记录每个块是否有一条边通向更小的 a 值
    vector<bool> hasLower(n + 1, false);

    for (auto [u, v] : edges) {
        int ru = dsu.find(u);
        int rv = dsu.find(v);

        if (a[u] > a[v]) {
            hasLower[ru] = true;
        } else if (a[v] > a[u]) {
            hasLower[rv] = true;
        }
    }

    // 第 3 步：检查唯一零值块，以及每个正值块能否向下走
    int zeroBlockCount = 0;
    bool ok = true;

    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) != i) continue; // 只检查每个块的代表元

        if (a[i] == 0) {
            zeroBlockCount++;
        } else if (!hasLower[i]) {
            ok = false;
        }
    }

    if (zeroBlockCount != 1) {
        ok = false;
    }

    if (!ok) {
        cout << -1 << '\n';
        return 0;
    }

    // 第 4 步：构造边权
    for (auto [u, v] : edges) {
        cout << abs(a[u] - a[v]) << '\n';
    }

    return 0;
}
```

---


