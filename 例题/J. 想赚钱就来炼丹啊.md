# [[0]]

> **原题链接:** ()

**涉及知识点:** [[小根堆]], [[优先队列]]，[[补题]],[[多维状态]],[[]]

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

using int64 = long long;

struct Node {
    int64 value;
    int x, y, z;

    bool operator>(const Node& other) const {
        return value > other.value;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<int64> a(n), b(n), c(n);

        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        for (auto& x : c) cin >> x;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        priority_queue<Node, vector<Node>, greater<Node>> heap;

        auto push = [&](int x, int y, int z) {
            heap.push({
                a[x] * b[y] * c[z],
                x, y, z
            });
        };

        push(0, 0, 0);

        for (int count = 0; count < m; ++count) {
            Node cur = heap.top();
            heap.pop();

            if (count) cout << ' ';
            cout << cur.value;

            int x = cur.x;
            int y = cur.y;
            int z = cur.z;

            if (x + 1 < n) {
                push(x + 1, y, z);
            }

            if (x == 0 && y + 1 < n) {
                push(0, y + 1, z);
            }

            if (x == 0 && y == 0 && z + 1 < n) {
                push(0, 0, z + 1);
            }
        }

        cout << '\n';
    }

    return 0;
}
```

---


