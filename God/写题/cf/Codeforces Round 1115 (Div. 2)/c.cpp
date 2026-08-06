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
    vector<int> weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    vector<vector<int>> graph(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> graph[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(graph[i].rbegin(), graph[i].rend());
    }
    vector<int> count(n + 1, -1);
    int ans = m;
    for (int i = n; i >= 1; i--)
    {
        ll sum = 0;
        for (int j = 1; j <= m;j++)
            sum += graph[i][j];
            heap.push(graph[i][j]);

    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}