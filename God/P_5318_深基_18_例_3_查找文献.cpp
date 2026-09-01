#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    vector<bool> visited(n + 1, false);
    vector<int> dfsorder(n);
    vector<pair<int, int>> st;
    visited[1] = true;
    st.push_back({1, 0});

    while (!st.empty())
    {
        int x = st.back().first;
        int &idx = st.back().second;

        while (idx < (int)graph[x].size() && visited[graph[x][idx]])
        {
            idx++;
        }
        if (idx == graph[x].size())
        {
            st.pop_back();
        }
        else
        {
            int v = graph[x][idx];
            visited[v] = true;
            idx++;
            dfsorder.push_back(v);
            st.push_back({v, 0});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}