# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[需重刷]]


```cpp
// 061 Code02 Prim算法优化（静态空间实现）

// 测试链接 : https://www.luogu.com.cn/problem/P3366
// 核心思路：严格对标 Java 版极致优化实现。
// 1. 建图：使用链式前向星（静态数组），彻底规避动态内存分配。
// 2. 堆结构：手写针对点数优化的索引堆（Index Heap），实现 O(1) 的位置查询与 O(log N) 的向上调整，
//    完美解决了原生 std::priority_queue 无法高效更新已有节点权值的痛点。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 针对洛谷等平台的快读模板
inline bool read(int &x) {
    x = 0; int f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == EOF) return false;
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
    return true;
}

class PrimStatic {
private:
    // 链式前向星建图
    vector<int> head;
    vector<int> nxt; // C++ 中避开 std::next 关键字
    vector<int> to;
    vector<int> weight;
    int cnt;

    // 改写的堆结构
    // heap_u 存节点 u，heap_w 存对应的花费 w
    vector<int> heap_u;
    vector<int> heap_w;
    
    // where[v] = -1，表示 v 这个节点，从来没有进入过堆
    // where[v] = -2，表示 v 这个节点，已经弹出过了
    // where[v] = i (>=0)，表示 v 这个节点，在堆上的 i 位置
    vector<int> where;
    int heapSize;
    int nodeCnt;

    // 弹出的堆顶记录
    int pop_u;
    int pop_w;

public:
    PrimStatic(int n, int m) {
        // 由于是无向图，边的数量需要乘 2
        int maxm = (m + 5) * 2;
        int maxn = n + 5;
        
        head.assign(maxn, 0);
        nxt.assign(maxm, 0);
        to.assign(maxm, 0);
        weight.assign(maxm, 0);
        cnt = 1;

        heap_u.assign(maxn, 0);
        heap_w.assign(maxn, 0);
        where.assign(maxn, -1);
        
        heapSize = 0;
        nodeCnt = 0;
    }

    void addEdge(int u, int v, int w) {
        nxt[cnt] = head[u];
        to[cnt] = v;
        weight[cnt] = w;
        head[u] = cnt++;
    }

    // 堆上，i 位置的信息 和 j 位置的信息 交换！
    void swapNode(int i, int j) {
        int a = heap_u[i];
        int b = heap_u[j];
        where[a] = j;
        where[b] = i;
        swap(heap_u[i], heap_u[j]);
        swap(heap_w[i], heap_w[j]);
    }

    void heapInsert(int i) {
        while (heap_w[i] < heap_w[(i - 1) / 2]) {
            swapNode(i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }

    void heapify(int i) {
        int l = i * 2 + 1;
        while (l < heapSize) {
            int best = l + 1 < heapSize && heap_w[l + 1] < heap_w[l] ? l + 1 : l;
            best = heap_w[best] < heap_w[i] ? best : i;
            if (best == i) {
                break;
            }
            swapNode(best, i);
            i = best;
            l = i * 2 + 1;
        }
    }

    // 当前处理的是编号为 ei 的边！
    void addOrUpdateOrIgnore(int ei) {
        int v = to[ei];
        int w = weight[ei];
        // 去往 v 点，权重 w
        if (where[v] == -1) {
            // v 这个点，从来没有进入过堆！
            heap_u[heapSize] = v;
            heap_w[heapSize] = w;
            where[v] = heapSize++;
            heapInsert(where[v]);
        } else if (where[v] >= 0) {
            // v 这个点的记录，在堆上的位置是 where[v]
            heap_w[where[v]] = min(heap_w[where[v]], w);
            heapInsert(where[v]); // 只有变小才需要往上调整
        }
    }

    void pop() {
        pop_u = heap_u[0];
        pop_w = heap_w[0];
        swapNode(0, --heapSize);
        heapify(0);
        where[pop_u] = -2;
        nodeCnt++;
    }

    bool isEmpty() {
        return heapSize == 0;
    }

    int prim() {
        // 1 节点出发
        nodeCnt = 1;
        where[1] = -2;
        for (int ei = head[1]; ei > 0; ei = nxt[ei]) {
            addOrUpdateOrIgnore(ei);
        }
        int ans = 0;
        while (!isEmpty()) {
            pop();
            ans += pop_w;
            for (int ei = head[pop_u]; ei > 0; ei = nxt[ei]) {
                addOrUpdateOrIgnore(ei);
            }
        }
        return ans;
    }

    int getNodeCnt() {
        return nodeCnt;
    }
};

int main() {
    int n, m;
    // 持续读取直到 EOF
    while (read(n) && read(m)) {
        // 每组数据新实例化一个对象，清理状态
        PrimStatic ps(n, m);
        
        for (int i = 0; i < m; i++) {
            int u, v, w;
            read(u);
            read(v);
            read(w);
            ps.addEdge(u, v, w);
            ps.addEdge(v, u, w); // 无向图双向建边
        }
        
        int ans = ps.prim();
        if (ps.getNodeCnt() == n) {
            printf("%d\n", ans);
        } else {
            printf("orz\n");
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
