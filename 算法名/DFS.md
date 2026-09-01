

非递归的DFS

```cpp
vector<char> visited(n + 1, false);
vector<int> dfsOrder;
vector<pair<int, int>> st;

// 相当于调用 dfs(1)
visited[1] = true;
dfsOrder.push_back(1);
st.push_back({1, 0});

while (!st.empty()) {
    // 取出当前正在处理的“函数调用”
    int u = st.back().first;
    int &idx = st.back().second;

    // 跳过已经访问过的邻接点
    while (idx < (int)graph[u].size() &&
           visited[graph[u][idx]]) {
        ++idx;
    }

    // 当前文章的所有邻接点都处理完了
    if (idx == (int)graph[u].size()) {
        st.pop_back();
    } else {
        // 找到下一个没访问过的文章
        int v = graph[u][idx];

        // 先把 idx 加一，表示这个邻接点已经处理过
        ++idx;

        visited[v] = true;
        dfsOrder.push_back(v);

        // 相当于递归调用 dfs(v)
        st.push_back({v, 0});
    }
}
```