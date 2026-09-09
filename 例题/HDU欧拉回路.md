# []

> **原题链接:** ()

**涉及知识点:** [[算法名/欧拉回路|欧拉回路]], [[]]，[[补题]],[[]],[[]]

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
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class DSU {
private:
    vector<int> parent, size;

public:
    explicit DSU(int n) : parent(n + 1), size(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    while (cin >> n && n != 0) {
        cin >> m;

        DSU dsu(n);
        vector<int> degree(n + 1, 0);

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;

            ++degree[u];
            ++degree[v];
            dsu.unite(u, v);
        }

        bool valid = true;
        int root = dsu.find(1);

        for (int i = 1; i <= n; ++i) {
            if (degree[i] % 2 != 0 || dsu.find(i) != root) {
                valid = false;
                break;
            }
        }

        cout << (valid ? 1 : 0) << '\n';
    }

    return 0;
}
```

---


