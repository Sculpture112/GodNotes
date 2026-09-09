# [[0]]

> **原题链接:** (https://acm.hdu.edu.cn/showproblem.php?pid=1878)

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

```cpp
#include <iostream>
using namespace std;

const int MAXN = 1005;

int parentArr[MAXN];
int degreeArr[MAXN];

// 查找节点 x 所在连通块的根节点
int findRoot(int x) {
    if (parentArr[x] == x) {
        return x;
    }

    return parentArr[x] = findRoot(parentArr[x]);
}

// 合并 a、b 所在的连通块
void unite(int a, int b) {
    int rootA = findRoot(a);
    int rootB = findRoot(b);

    if (rootA != rootB) {
        parentArr[rootA] = rootB;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    while (cin >> n && n != 0) {
        cin >> m;

        // 初始化并查集和度数数组
        for (int i = 1; i <= n; ++i) {
            parentArr[i] = i;
            degreeArr[i] = 0;
        }

        // 读取所有边
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;

            ++degreeArr[u];
            ++degreeArr[v];

            unite(u, v);
        }

        bool valid = true;
        int root = findRoot(1);

        // 检查连通性和度数
        for (int i = 1; i <= n; ++i) {
            if (findRoot(i) != root || degreeArr[i] % 2 != 0) {
                valid = false;
                break;
            }
        }

        cout << (valid ? 1 : 0) << '\n';
    }

    return 0;
}
```
