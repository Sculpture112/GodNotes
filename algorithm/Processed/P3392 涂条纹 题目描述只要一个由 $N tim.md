# P3392 涂条纹 题目描述只要一个由 $N tim

> # P3392 涂条纹## 题目描述只要一个由 $N \times M$ 个小方块组成的旗帜符合如下规则，就是合法的图案。- 从最上方若干行（至少一行）的格子全部是白色的；- 接下来若干行（至少一行）的格子全部是蓝色的；- 剩下的行（至少一行）全部是红色的；现有一个棋盘状的布，分成了 $N$ 行 $M$ 列的格子，每个格子是白色蓝色红色之一，小 a 希望把这个布改成合法图案，方法是在一些格子上涂颜料，盖住之前的颜色。小 A 很懒，希望涂最少的格子，使这块布成为一个合法的图案。## 输入格式第一行是两个整数 $N,M$。接下来 $N$ 行是一个矩阵，矩阵的每一个小方块是 `W`（白），`B`（蓝），`R`（红）中的一个。## 输出格式一个整数，表示至少需要涂多少块。## 输入输出样例 #1### 输入 #1```4 5WRWRWBWRWBWRWRWRWBWR```### 输出 #1```11```## 说明/提示### 样例解释目标状态是：```plainWWWWWBBBBBRRRRRRRRRR```一共需要改 $11$ 个格子。### 数据范围对于 $100\%$ 的数据，$N,M \leq 50$。

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> flag(n);
    for (int i = 0; i < n; ++i) cin >> flag[i];

    int min_paint = 1e9;

    // 枚举白色最后一行的下标 i (0 ~ n-3)
    for (int i = 0; i <= n - 3; ++i) {
        // 枚举蓝色最后一行的下标 j (i+1 ~ n-2)
        for (int j = i + 1; j <= n - 2; ++j) {
            int current_paint = 0;

            // 统计白色区域 (0 to i)
            for (int r = 0; r <= i; ++r)
                for (int c = 0; c < m; ++c) if (flag[r][c] != 'W') current_paint++;

            // 统计蓝色区域 (i+1 to j)
            for (int r = i + 1; r <= j; ++r)
                for (int c = 0; c < m; ++c) if (flag[r][c] != 'B') current_paint++;

            // 统计红色区域 (j+1 to n-1)
            for (int r = j + 1; r < n; ++r)
                for (int c = 0; c < m; ++c) if (flag[r][c] != 'R') current_paint++;

            min_paint = min(min_paint, current_paint);
        }
    }

    cout << min_paint << endl;
    return 0;
}
```
