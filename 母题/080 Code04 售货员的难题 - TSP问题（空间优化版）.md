# [080 Code04 售货员的难题 - TSP问题（空间优化版）]

> **原题链接:** (https://www.luogu.com.cn/problem/P1171)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
// 售货员的难题 - TSP问题
// 某乡有n个村庄(1<=n<=20)，有一个售货员，他要到各个村庄去售货
// 各村庄之间的路程s(1<=s<=1000)是已知的
// 且A村到B村的路程，与B到A的路大多不同(有向带权图)
// 为了提高效率，他从商店出发到每个村庄一次，然后返回商店所在的村，
// 假设商店所在的村庄为1
// 他不知道选择什么样的路线才能使所走的路程最短
// 请你帮他选择一条最短的路
// 测试链接 : https://www.luogu.com.cn/problem/P1171
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 19;
const int INF = 0x3f3f3f3f;

int n;
int startCost[MAXN];
int backCost[MAXN];
int graph[MAXN][MAXN];
int dp[1 << MAXN][MAXN];

void build() {
    for (int s = 0; s < (1 << n); s++) {
        for (int i = 0; i < n; i++) {
            dp[s][i] = -1;
        }
    }
}

int f(int s, int i) {
    if (s == (1 << n) - 1) {
        return backCost[i];
    }
    int &ans = dp[s][i];
    if (ans != -1) {
        return ans;
    }
    ans = INF;
    for (int j = 0; j < n; j++) {
        if ((s & (1 << j)) == 0) {
            ans = min(ans, graph[i][j] + f(s | (1 << j), j));
        }
    }
    return ans;
}

int compute() {
    int ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, startCost[i] + f(1 << i, i));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int total;
    while (cin >> total) {
        n = total - 1;
        build();

        int ignore;
        cin >> ignore;
        for (int i = 0; i < n; i++) {
            cin >> startCost[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> backCost[i];
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }

        cout << compute() << '\n';
    }

    return 0;
}
```

---

