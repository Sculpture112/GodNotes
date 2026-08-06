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

    vector<vector<int>> graph(n, vector<int>(m));
    for (int i = 0; i <= n-1; i++)
    {
        for (int j = 0; j <= m-1; j++)
        {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i <= n-1; i++)
    {
        sort(graph[i].rbegin(), graph[i].rend());
    }
    int ans = m;
    priority_queue<int> heap, heap2;
    for (int i = n-1; i >= 0; i--)
    {
        ll sum = 0;
        int cnt = 0;
        for (int j = 0; j <= m-1; j++)
        {
            heap.push(graph[i][j]);
        }
        heap2 = heap;
        while (!heap.empty() && sum < weight[i - 1])
        {
            sum += heap.top();
            heap.pop();
            cnt++;
        }
        heap = heap2;
        if (sum >= weight[i - 1])
        {
            ans = min(ans, cnt);
        }
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