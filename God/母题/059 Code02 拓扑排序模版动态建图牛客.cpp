#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> indegree(n + 1, 0);
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegree[v]++;
    }
    int l = 0, r = 0;
    vector<int> queue(n, 0);

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            queue[r++] = i;
        }
    }
    int cnt = 0;

    while (l < r)
    {
        int cur = queue[l++];
        cnt++;
        for (int nxt : graph[cur])
        {
            if (--indegree[nxt] == 0)
            {
                queue[r++] = nxt;
            }
        }
    }

    if(cnt != n){
        cout << -1;
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << queue[i] << " ";
    }
    cout << queue[n - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
