# []

> **原题链接:** (https://www.luogu.com.cn/problem/P3366)

**涉及知识点:** [[]], [[]]，[[]],[[]],[[]]

**核心套路:** 

## 破题切入点(思维闪念)
[]



```cpp
#include <bits/stdc++.h>

using namespace std;

// Kruskal算法模版（洛谷）
// 静态空间实现
// 测试链接 : https://www.luogu.com.cn/problem/P3366
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过

// 时间复杂度O(m * log m) + O(n + m)
const int MAXN = 5001;
const int MAXM = 200001;

int father[MAXN];

// u, v, w
int edges[MAXM][3];

int n, m;

void build() {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
}

int find(int i) {
    if (i != father[i]) {
        father[i] = find(father[i]);
    }
    return father[i];
}

// 如果x和y本来就是一个集合，返回false
// 如果x和y不是一个集合，合并之后返回true
bool unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        father[fx] = fy;
        return true;
    } else {
        return false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m) {
        build();
        for (int i = 0; i < m; i++) {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }
        sort(edges, edges + m, [](const int (&a)[3], const int (&b)[3]) {
    return a[2] < b[2];
});
        int ans = 0;
        int edgeCnt = 0;
        for (int i = 0; i < m; i++) {
            if (unite(edges[i][0], edges[i][1])) {
                edgeCnt++;
                ans += edges[i][2];
            }
        }
        if (edgeCnt == n - 1) {
            cout << ans << '\n';
        } else {
            cout << "orz" << '\n';
        }
    }
    return 0;
}
```

---

