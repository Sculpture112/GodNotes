# []

> **原题链接:** (https://www.luogu.com.cn/problem/P2853)

**涉及知识点:** [[BFS]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N, M;
    cin >> K >> N >> M;

    vector<int> cows(K);
    for (int i = 0; i < K; ++i) {
        cin >> cows[i];
    }

    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        graph[A].push_back(B);
    }

    vector<int> reached(N + 1, 0);

    for (int start : cows) {
        vector<bool> visited(N + 1, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            ++reached[u];

            for (int v : graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i) {
        if (reached[i] == K) {
            ++answer;
        }
    }

    cout << answer << '\n';
    return 0;
}
```

---


