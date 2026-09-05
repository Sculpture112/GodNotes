# []

> **原题链接:** (https://www.luogu.com.cn/problem/P1825)

**涉及知识点:** [[BFS]], [[传送门]]，[[补题]],[[0]],[[]]

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> maze(N);
    vector<pair<int, int>> pos[26];
    int sr = 0, sc = 0;

    for (int i = 0; i < N; ++i) {
        cin >> maze[i];
        for (int j = 0; j < M; ++j) {
            char ch = maze[i][j];
            if (ch == '@') {
                sr = i;
                sc = j;
            } else if (ch >= 'A' && ch <= 'Z') {
                pos[ch - 'A'].push_back({i, j});
            }
        }
    }

    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int, int>> q;

    dist[sr][sc] = 0;
    q.push({sr, sc});

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (maze[r][c] == '=') {
            cout << dist[r][c] << '\n';
            return 0;
        }

        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (maze[nr][nc] == '#') continue;

            int tr = nr, tc = nc;
            char ch = maze[nr][nc];

            // 走到传送门后，立即传送到另一个端点
            if (ch >= 'A' && ch <= 'Z') {
                auto &v = pos[ch - 'A'];
                if (v[0] == make_pair(nr, nc)) {
                    tr = v[1].first;
                    tc = v[1].second;
                } else {
                    tr = v[0].first;
                    tc = v[0].second;
                }
            }

            if (dist[tr][tc] == -1) {
                dist[tr][tc] = dist[r][c] + 1;
                q.push({tr, tc});
            }
        }
    }

    return 0;
}
```

---


