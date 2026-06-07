# [080 Code04 售货员的难题 - TSP问题（空间优化版）]

> **原题链接:** (https://www.luogu.com.cn/problem/P1171)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>

using namespace std;

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

// 卡空间是吧？绕一下！
class Code04_TSP2 {
public:
    int MAXN = 19;
    int n;
    vector<int> start;
    vector<int> back;

    // 这个图中，其实是不算起始村的，其他村庄彼此到达的路径长度
    vector<vector<int>> graph;

    // 不算起始村庄的
    vector<vector<int>> dp;

    void build() {
        start.assign(n, 0);
        back.assign(n, 0);
        graph.assign(n, vector<int>(n, 0));
        dp.assign(1 << n, vector<int>(n, -1));
    }

    int compute() {
        int ans = INT_MAX;
        // 起始村无编号
        for (int i = 0; i < n; i++) {
            // 起始村 -> i号村  +  i号村出发所有村子都走最终回到起始村
            ans = min(ans, start[i] + f(1 << i, i));
        }
        return ans;
    }

    // s : 不包含起始村的
    int f(int s, int i) {
        if (s == (1 << n) - 1) {
            return back[i];
        }
        if (dp[s][i] != -1) {
            return dp[s][i];
        }
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            if ((s & (1 << j)) == 0) {
                ans = min(ans, graph[i][j] + f(s | (1 << j), j));
            }
        }
        dp[s][i] = ans;
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Code04_TSP2 solver;
    int total;
    while (cin >> total) {
        solver.n = total - 1;
        solver.build();
        int ignore;
        cin >> ignore;
        for (int i = 0; i < solver.n; i++) {
            cin >> solver.start[i];
        }
        for (int i = 0; i < solver.n; i++) {
            cin >> solver.back[i];
            for (int j = 0; j < solver.n; j++) {
                cin >> solver.graph[i][j];
            }
        }
        cout << solver.compute() << '\n';
    }
    return 0;
}
```

---
