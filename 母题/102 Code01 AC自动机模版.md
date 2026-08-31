# []

> **原题链接:** (https://www.luogu.com.cn/problem/P5357)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>

using namespace std;

// AC自动机模版(优化版)
// 给你若干目标字符串，还有一篇文章
// 返回每个目标字符串在文章中出现了几次
// 测试链接 : https://www.luogu.com.cn/problem/P5357
// 请同学们务必参考如下代码中关于输入、输出的处理
// 这是输入输出处理效率很高的写法
// 提交以下的code，提交时请把类名改成"Main"，可以直接通过

// 目标字符串的数量
const int MAXN = 200001;

// 所有目标字符串的总字符数量
const int MAXS = 200001;

// 记录每个目标串的结尾节点编号
int endNode[MAXN];

// AC自动机
int tree[MAXS][26];
int fail[MAXS];
int cnt = 0;

// 具体题目相关，本题为收集词频
// 所以每个节点记录词频
int times[MAXS];

// 可以用作队列或者栈，一个容器而已
int box[MAXS];

// 链式前向星，为了建立fail指针的反图
int head[MAXS];
int nextEdge[MAXS];
int to[MAXS];
int edge = 0;

// 遍历fail反图，递归方法会爆栈，所以用非递归替代
bool visited[MAXS];

// AC自动机加入目标字符串
void insertString(int i, const string& str) {
    int u = 0;
    for (int j = 0; j < str.length(); j++) {
        int c = str[j] - 'a';
        if (tree[u][c] == 0) {
            tree[u][c] = ++cnt;
        }
        u = tree[u][c];
    }
    // 每个目标字符串的结尾节点编号
    endNode[i] = u;
}

// 加入所有目标字符串之后
// 设置fail指针 以及 设置直接直通表
// 做了AC自动机固定的优化
void setFail() {
    // box当做队列来使用
    int l = 0;
    int r = 0;
    for (int i = 0; i <= 25; i++) {
        if (tree[0][i] > 0) {
            box[r++] = tree[0][i];
        }
    }
    while (l < r) {
        int u = box[l++];
        for (int i = 0; i <= 25; i++) {
            if (tree[u][i] == 0) {
                tree[u][i] = tree[fail[u]][i];
            } else {
                fail[tree[u][i]] = tree[fail[u]][i];
                box[r++] = tree[u][i];
            }
        }
    }
}

void addEdge(int u, int v) {
    nextEdge[++edge] = head[u];
    head[u] = edge;
    to[edge] = v;
}

// 逻辑是对的
// 但是递归开太多层了会爆栈
// C++这道题不会爆栈
// java会
void f1(int u) {
    for (int i = head[u]; i > 0; i = nextEdge[i]) {
        f1(to[i]);
        times[u] += times[to[i]];
    }
}

// 改成非递归才能通过
// 因为是用栈来模拟递归
// 只消耗内存空间(box和visited)
// 不消耗系统栈的空间
// 所以很安全
void f2(int u) {
    // box当做栈来使用
    int r = 0;
    box[r++] = u;
    int cur;
    while (r > 0) {
        cur = box[r - 1];
        if (!visited[cur]) {
            visited[cur] = true;
            for (int i = head[cur]; i > 0; i = nextEdge[i]) {
                box[r++] = to[i];
            }
        } else {
            r--;
            for (int i = head[cur]; i > 0; i = nextEdge[i]) {
                times[cur] += times[to[i]];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        insertString(i, str);
    }
    setFail();
    string s;
    cin >> s;
    for (int u = 0, i = 0; i < s.length(); i++) {
        u = tree[u][s[i] - 'a'];
        // 增加匹配次数
        times[u]++;
    }
    for (int i = 1; i <= cnt; i++) {
        // 根据fail指针建反图
        // 其实是一颗树
        addEdge(fail[i], i);
    }
    // 遍历fail指针建的树
    // 汇总每个节点的词频
    f2(0);
    for (int i = 1; i <= n; i++) {
        cout << times[endNode[i]] << '\n';
    }
    return 0;
}
```

---

