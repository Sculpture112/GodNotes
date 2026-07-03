# []

> **原题链接:** (https://vjudge.net/contest/826612#problem/G)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

int H, W, K;
vector<string> grid;
long long ans = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int step) {
    if (step == K) {
        ans++;
        return;
    }

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
        if (grid[nx][ny] == '#') continue;

        grid[nx][ny] = '#';
        dfs(nx, ny, step + 1);
        grid[nx][ny] = '.';
    }
}

int main() {
    cin >> H >> W >> K;

    grid.resize(H);
    for (int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (grid[i][j] == '.') {
                grid[i][j] = '#';
                dfs(i, j, 0);
                grid[i][j] = '.';
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
```

---


