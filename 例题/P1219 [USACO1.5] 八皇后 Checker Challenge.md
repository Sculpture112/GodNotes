# []

> **原题链接:** (https://www.luogu.com.cn/problem/P1219)

**涉及知识点:** [[DFS]], [[主对角线]]，[[补题]],[[副对角线]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <iostream>
using namespace std;

int n;
int path[15];
bool col[15];
bool diagonal1[30]; // row - column + n
bool diagonal2[30]; // row + column
int answerCount = 0;

void dfs(int row) {
    if (row > n) {
        ++answerCount;

        if (answerCount <= 3) {
            for (int i = 1; i <= n; ++i) {
                if (i > 1) cout << ' ';
                cout << path[i];
            }
            cout << '\n';
        }
        return;
    }

    // 从小到大枚举列，保证方案按字典序产生
    for (int column = 1; column <= n; ++column) {
        int d1 = row - column + n;
        int d2 = row + column;

        if (col[column] || diagonal1[d1] || diagonal2[d2]) {
            continue;
        }

        path[row] = column;
        col[column] = true;
        diagonal1[d1] = true;
        diagonal2[d2] = true;

        dfs(row + 1);

        col[column] = false;
        diagonal1[d1] = false;
        diagonal2[d2] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    dfs(1);

    cout << answerCount << '\n';
    return 0;
}
```

---


