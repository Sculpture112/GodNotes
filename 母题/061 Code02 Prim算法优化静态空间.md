# []

> **原题链接:** (https://www.luogu.com.cn/problem/P3366)

**涉及知识点:** [[]], [[]]，[[]],[[]],[[]]

**核心套路:** 

## 破题切入点(思维闪念)
[]



```cpp
#include <bits/stdc++.h>

using namespace std;

// Prim算法优化（洛谷）
// 静态空间实现
// 时间复杂度O(n + m) + O((m+n) * log n)
// 测试链接 : https://www.luogu.com.cn/problem/P3366
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下所有代码，把主类名改成Main，可以直接通过

// 建图用链式前向星
// 堆也是用数组结构手写的、且只和节点个数有关
// 这个实现留给有需要的同学
// 但是一般情况下并不需要做到这个程度

const int MAXN = 5001;
const int MAXM = 400001;

int n, m;

// 链式前向星建图
int head[MAXN];
int nxt[MAXM];
int to[MAXM];
int weight[MAXM];
int cnt;

// 改写的堆结构
int heapArr[MAXN][2];

// where[v] = -1，表示v这个节点，从来没有进入过堆
// where[v] = -2，表示v这个节点，已经弹出过了
// where[v] = i(>=0)，表示v这个节点，在堆上的i位置
int whereArr[MAXN];

// 堆的大小
int heapSize;

// 找到的节点个数
int nodeCnt;

void build() {
    cnt = 1;
    heapSize = 0;
    nodeCnt = 0;
    fill(head + 1, head + n + 1, 0);
    fill(whereArr + 1, whereArr + n + 1, -1);
}

void addEdge(int u, int v, int w) {
    nxt[cnt] = head[u];
    to[cnt] = v;
    weight[cnt] = w;
    head[u] = cnt++;
}

// 堆上，i位置的信息 和 j位置的信息 交换！
void swapHeap(int i, int j) {
    int a = heapArr[i][0];
    int b = heapArr[j][0];
    whereArr[a] = j;
    whereArr[b] = i;
    swap(heapArr[i][0], heapArr[j][0]);
    swap(heapArr[i][1], heapArr[j][1]);
}

void heapInsert(int i) {
    while (heapArr[i][1] < heapArr[(i - 1) / 2][1]) {
        swapHeap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

void heapify(int i) {
    int l = i * 2 + 1;
    while (l < heapSize) {
        int best = l + 1 < heapSize && heapArr[l + 1][1] < heapArr[l][1] ? l + 1 : l;
        best = heapArr[best][1] < heapArr[i][1] ? best : i;
        if (best == i) {
            break;
        }
        swapHeap(best, i);
        i = best;
        l = i * 2 + 1;
    }
}

bool isEmpty() {
    return heapSize == 0;
}

// 当前处理的是编号为ei的边！
void addOrUpdateOrIgnore(int ei) {
    int v = to[ei];
    int w = weight[ei];
    // 去往v点，权重w
    if (whereArr[v] == -1) {
        // v这个点，从来没有进入过堆！
        heapArr[heapSize][0] = v;
        heapArr[heapSize][1] = w;
        whereArr[v] = heapSize++;
        heapInsert(whereArr[v]);
    } else if (whereArr[v] >= 0) {
        // v这个点的记录，在堆上的位置是where[v]
        heapArr[whereArr[v]][1] = min(heapArr[whereArr[v]][1], w);
        heapInsert(whereArr[v]);
    }
}

int u;
int w;

// 堆顶的记录：节点 -> u、到节点的花费 -> w
void popHeap() {
    u = heapArr[0][0];
    w = heapArr[0][1];
    swapHeap(0, --heapSize);
    heapify(0);
    whereArr[u] = -2;
    nodeCnt++;
}

int prim() {
    // 1节点出发
    nodeCnt = 1;
    whereArr[1] = -2;
    for (int ei = head[1]; ei > 0; ei = nxt[ei]) {
        addOrUpdateOrIgnore(ei);
    }
    int ans = 0;
    while (!isEmpty()) {
        popHeap();
        ans += w;
        for (int ei = head[u]; ei > 0; ei = nxt[ei]) {
            addOrUpdateOrIgnore(ei);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m) {
        build();
        for (int i = 0, u, v, w; i < m; i++) {
            cin >> u >> v >> w;
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        int ans = prim();
        if (nodeCnt == n) {
            cout << ans << '\n';
        } else {
            cout << "orz" << '\n';
        }
    }
    return 0;
}
```

---

