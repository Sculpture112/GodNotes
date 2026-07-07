# []

> **原题链接:** ()

**涉及知识点:** [[DFS]], [[回溯算法]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;
vector<string> grid;

int h, w, k;
long long ans = 0;
int dx[4] = {1, 0, -1, 0};

int dy[4] = {0, -1, 0, 1};

void dfs(int x, int y, int step)
{
    if(step == k){
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= h || ny < 0 || ny >= w)
        {
            continue;
        }
        if (grid[nx][ny] == '#')
        {
            continue;
        }
        grid[nx][ny] = '#';
        dfs(nx, ny, step + 1);
        grid[nx][ny] = '.';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> w >> k;
    grid.resize(h);
    for (int i = 0; i < h; i++)
    {
        cin >> grid[i];
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == '.')
            {
                grid[i][j] = '#';
                dfs(i, j, 0);
                grid[i][j] = '.';
            }
        }
    }
    cout << ans;

    return 0;
}
```

---


