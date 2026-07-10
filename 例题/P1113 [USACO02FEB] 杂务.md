# []

> **原题链接:** (https://www.luogu.com.cn/problem/P1113)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> len(n + 1);       // 每项任务的耗时
    vector<int> in(n + 1);        // 入度：还有多少前置任务
    vector<int> finish(n + 1);    // 最早完成时刻
    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= n; i++) {
        int id, pre;
        cin >> id >> len[id];

        while (cin >> pre && pre != 0) {
            g[pre].push_back(id); // pre 完成后，id 才能开始
            in[id]++;
        }
    }

    queue<int> q;

    // 没有前置任务的工作，可以立刻开始
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            finish[i] = len[i];
            q.push(i);
        }
    }

    int ans = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        ans = max(ans, finish[u]);

        for (int v : g[u]) {
            // u 是 v 的一个前置任务：
            // v 必须等最晚完成的前置任务结束后，才能做自己的 len[v] 时间
	            finish[v] = max(finish[v], finish[u] + len[v]);

            if (--in[v] == 0) {
                q.push(v);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
```

---


