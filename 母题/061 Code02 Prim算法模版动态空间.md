# []

> **原题链接:** (https://www.luogu.com.cn/problem/P3366)

**涉及知识点:** [[]], [[]]，[[]],[[]],[[]]

**核心套路:** 

## 破题切入点(思维闪念)
[]



```cpp
#include <bits/stdc++.h>

using namespace std;

// Prim算法模版（洛谷）
// 动态空间实现
// 测试链接 : https://www.luogu.com.cn/problem/P3366
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过

// 时间复杂度O(n + m) + O(m * log m)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0, u, v, w; i < m; i++) {
            cin >> u >> v >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
        // int[] record
        // record[0] : 到达的节点
        // record[1] : 到达的花费
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (auto& edge : graph[1]) {
            heap.push({edge.second, edge.first});
        }
        // 哪些节点已经发现过了
        vector<bool> set(n + 1, false);
        int nodeCnt = 1;
        set[1] = true;
        int ans = 0;
        while (!heap.empty()) {
            auto [cost, next] = heap.top();
            heap.pop();
            if (!set[next]) {
                nodeCnt++;
                set[next] = true;
                ans += cost;
                for (auto& e : graph[next]) {
                    heap.push({e.second, e.first});
                }
            }
        }
        if (nodeCnt == n) {
            cout << ans << '\n';
        } else {
            cout << "orz" << '\n';
        }
    }
    return 0;
}
```

---

