# []

> **原题链接:** (https://www.luogu.com.cn/problem/P2895)

**涉及知识点:** [[BFS]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 305;
const int INF = 0x3f3f3f3f;

int dangerTime[N][N];
int dista[N][N];

int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;

    memset(dangerTime, 0x3f, sizeof dangerTime);
    memset(dista, -1, sizeof dista);

    for (int i = 0; i < M; ++i) {
        int x, y, t;
        cin >> x >> y >> t;

        // 流星会摧毁中心格以及上下左右四个格子
        for (int k = 0; k < 5; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                dangerTime[nx][ny] = min(dangerTime[nx][ny], t);
            }
        }
    }

    // 时刻 0 原点就被摧毁，无法开始行动
    if (dangerTime[0][0] == 0) {
        cout << -1 << '\n';
        return 0;
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    dista[0][0] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        // 这个格子永远不会被流星波及
        if (dangerTime[x][y] == INF) {
            cout << dista[x][y] << '\n';
            return 0;
        }

        for (int k = 1; k < 5; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                continue;
            }

            if (dista[nx][ny] != -1) {
                continue;
            }

            int arriveTime = dista[x][y] + 1;

            // 必须在该格子被摧毁之前到达
            if (arriveTime < dangerTime[nx][ny]) {
                dista[nx][ny] = arriveTime;
                q.push({nx, ny});
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}
```

---


