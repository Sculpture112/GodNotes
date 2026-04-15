# []

> **原题链接:** (https://www.luogu.com.cn/problem/P4779)

**涉及知识点:** [[]], [[]]，[[需重刷]],[[]],[[]]

**难度 [[]]


```cpp
// 064 Code01 Dijkstra算法模版（洛谷）
// 静态空间实现 : 链式前向星 + 反向索引堆
// 测试链接 : https://www.luogu.com.cn/problem/P4779
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// C++ 提交时直接全部复制提交即可通过

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;

// 链式前向星
int head[MAXN];
int nxt[MAXM];
int to_node[MAXM];
int weight[MAXM];
int cnt;

// 反向索引堆
int heap_arr[MAXN];

// where[v] = -1，表示v这个节点，从来没有进入过堆
// where[v] = -2，表示v这个节点，已经弹出过了
// where[v] = i(>=0)，表示v这个节点，在堆上的i位置
int where[MAXN];
int heapSize;

int dist[MAXN];
int n, m, s;

void build() {
    cnt = 1;
    heapSize = 0;
    // C++ 中 fill 的区间是 [first, last)，所以尾部是 n + 1
    fill(head + 1, head + n + 1, 0);
    fill(where + 1, where + n + 1, -1);
    fill(dist + 1, dist + n + 1, INT_MAX);
}

// 链式前向星建图
void addEdge(int u, int v, int w) {
    nxt[cnt] = head[u];
    to_node[cnt] = v;
    weight[cnt] = w;
    head[u] = cnt++;
}

void swap_heap(int i, int j) {
    int tmp = heap_arr[i];
    heap_arr[i] = heap_arr[j];
    heap_arr[j] = tmp;
    where[heap_arr[i]] = i;
    where[heap_arr[j]] = j;
}

void heapInsert(int i) {
    while (dist[heap_arr[i]] < dist[heap_arr[(i - 1) / 2]]) {
        swap_heap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}

void addOrUpdateOrIgnore(int v, int w) {
    if (where[v] == -1) {
        heap_arr[heapSize] = v;
        where[v] = heapSize++;
        dist[v] = w;
        heapInsert(where[v]);
    } else if (where[v] >= 0) {
        dist[v] = min(dist[v], w);
        heapInsert(where[v]);
    }
}

void heapify(int i) {
    int l = i * 2 + 1;
    while (l < heapSize) {
        int best = l + 1 < heapSize && dist[heap_arr[l + 1]] < dist[heap_arr[l]] ? l + 1 : l;
        best = dist[heap_arr[best]] < dist[heap_arr[i]] ? best : i;
        if (best == i) {
            break;
        }
        swap_heap(best, i);
        i = best;
        l = i * 2 + 1;
    }
}

int pop_heap() {
    int ans = heap_arr[0];
    swap_heap(0, --heapSize);
    heapify(0);
    where[ans] = -2;
    return ans;
}

bool isEmpty() {
    return heapSize == 0;
}

void dijkstra() {
    addOrUpdateOrIgnore(s, 0);
    while (!isEmpty()) {
        int v = pop_heap();
        for (int ei = head[v]; ei > 0; ei = nxt[ei]) {
            addOrUpdateOrIgnore(to_node[ei], dist[v] + weight[ei]);
        }
    }
}

int main() {
    // C++ 的快速 I/O 模板，能够极大提升读写效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 持续读取输入，直到 EOF
    while (cin >> n >> m >> s) {
        build();
        for (int i = 0, u, v, w; i < m; i++) {
            cin >> u >> v >> w;
            addEdge(u, v, w);
        }
        
        dijkstra();
        
        // 按照洛谷要求的格式输出
        cout << dist[1];
        for (int i = 2; i <= n; i++) {
            cout << " " << dist[i];
        }
        cout << "\n";
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
