# []

> **原题链接:** (https://www.luogu.com.cn/problem/P3366)

**涉及知识点:** [[]], [[]]，[[需重刷]]


```cpp
// 061 Code01 Kruskal算法模版（洛谷）
// 静态空间实现
// 测试链接 : https://www.luogu.com.cn/problem/P3366
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// C++ 提交时直接全部复制提交即可通过

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 时间复杂度 O(m * log m) + O(n + m)

const int MAXN = 5005;
const int MAXM = 200005;

int father[MAXN];

// C++ 竞赛中推荐使用 struct 来表示边并重载小于号，以便于排序
struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

Edge edges[MAXM];
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

// union 是 C++ 的保留关键字，这里改名为 unionSet
// 如果 x 和 y 本来就是一个集合，返回 false
// 如果 x 和 y 不是一个集合，合并之后返回 true
bool unionSet(int x, int y) {
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
    // C++ 的快速 I/O 模板，能够极大提升读写效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 等同于 Java 中的 while (in.nextToken() != StreamTokenizer.TT_EOF)
    while (cin >> n >> m) {
        build();
        for (int i = 0; i < m; i++) {
            cin >> edges[i].u >> edges[i].v >> edges[i].w;
        }
        
        // 按照权值升序排序，利用了我们在 struct 中重载的 < 运算符
        sort(edges, edges + m);
        
        int ans = 0;
        int edgeCnt = 0;
        
        for (int i = 0; i < m; i++) {
            if (unionSet(edges[i].u, edges[i].v)) {
                edgeCnt++;
                ans += edges[i].w;
            }
        }
        
        if (edgeCnt == n - 1) {
            cout << ans << "\n";
        } else {
            cout << "orz\n";
        }
    }
    
    return 0;
	}
```

---


**核心套路:** [[]]
**前置母题/相似题目:** [[]]
**时空限制瓶颈:** []

---


## 破题切入点 (思维闪念)
[]
