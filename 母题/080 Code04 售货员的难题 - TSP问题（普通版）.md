# [080 Code04 售货员的难题 - TSP问题（普通版）]

> **原题链接:** (https://www.luogu.com.cn/problem/P1171)

**涉及知识点:** [[]], [[INF]]，[[补题]],[[]],[[]]
`const int INF = 0x3f3f3f3f` 就是一个大常数
它的意思是：
const int INF = 0x3f3f3f3f;
定义一个常量整数 INF，值是十六进制的 0x3f3f3f3f，换成十进制大约是：
1061109567
为什么常用它：
它足够大
对很多算法题来说，1e9 级别已经可以表示“当前不可达”或“很大”。

两个 INF 相加不容易溢出
0x3f3f3f3f + 0x3f3f3f3f = 0x7e7e7e7e，仍然小于 int 最大值 0x7fffffff。

可以用 memset 初始化
因为每个字节都是 0x3f，所以可以这样写：

int dist[1000];
memset(dist, 0x3f, sizeof(dist));
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

const int MAXN = 20;
const int INF = 0x3f3f3f3f;

int n;
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
        return graph[i][0];
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
    return f(1, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n) {
        build();
        for (int i = 0; i < n; i++) {
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

