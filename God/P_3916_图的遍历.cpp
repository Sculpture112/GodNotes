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
        graph[v].push_back(u);
    }

    vector<int> ans(n + 1, 0);
    vector<int> st;
    for (int i = n; i >= 1; i--)
    {
        if (ans[i] != 0)
            continue;
        st.push_back(i);
        ans[i] = i;

        while (!st.empty())
        {
            int u = st.back();
            st.pop_back();
            for (int v : graph[u])
            {
                if (ans[v] == 0)
                {
                    ans[v] = i;
                    st.push_back(v);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
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