# []

> **原题链接:** (https://www.luogu.com.cn/problem/P2910)

**涉及知识点:** [[已AC]], [[Floyd]]，[[需重刷]],[[]],[[]]

**难度 [[]]


```cpp
// 065 Code02 Floyd算法模版（洛谷）
// 测试链接 : https://www.luogu.com.cn/problem/P2910
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// C++ 提交时直接全部复制提交即可通过

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// 稍微开大一点防止越界
const int MAXN = 105;
const int MAXM = 10005;

int path_arr[MAXM];
int dist[MAXN][MAXN];

int n, m, ans;

// 初始时设置任意两点之间的最短距离为无穷大，表示任何路不存在
void build() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INT_MAX;
        }
    }
}

void floyd() {
    // O(N^3)的过程
    // 枚举每个跳板
    // 注意，跳板要最先枚举！跳板要最先枚举！跳板要最先枚举！
    for (int bridge = 0; bridge < n; bridge++) { // 跳板
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // i -> .....bridge .... -> j
                // distance[i][j]能不能缩短
                // distance[i][j] = min ( distance[i][j] , distance[i][bridge] + distance[bridge][j])
                // 防溢出判断，只有两个都不是无穷大时才相加
                if (dist[i][bridge] != INT_MAX 
                    && dist[bridge][j] != INT_MAX
                    && dist[i][j] > dist[i][bridge] + dist[bridge][j]) {
                    dist[i][j] = dist[i][bridge] + dist[bridge][j];
                }
            }
        }
    }
}

int main() {
    // C++ 的快速 I/O 模板，极大提升读写效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 等同于 Java 的 in.nextToken() != StreamTokenizer.TT_EOF
    while (cin >> n >> m) {
        for (int i = 0; i < m; i++) {
            cin >> path_arr[i];
            // 转换为 0 索引
            path_arr[i]--;
        }
        
        // 这道题给的图是邻接矩阵的形式
        // 任意两点之间的边权都会给定
        // 所以显得distance初始化不太必要
        // 但是一般情况下，distance初始化一定要做
        build();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> dist[i][j];
            }
        }
        
        floyd();
        
        ans = 0;
        for (int i = 1; i < m; i++) {
            ans += dist[path_arr[i - 1]][path_arr[i]];
        }
        cout << ans << "\n";
    }

    return 0;
}
```

---


**核心套路:** 
**前置母题/相似题目:** [[]]
**时空限制瓶颈:** []

---


## 破题切入点 (思维闪念)
[]
