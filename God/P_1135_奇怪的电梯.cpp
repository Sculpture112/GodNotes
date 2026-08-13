#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    a--, b--;
    queue<int> que;
    que.push(a);

    int step = 1;
    vector<int> dist(n, -1);
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            int cur = que.front();
            if (cur < 1 || cur > n)
                continue;
            que.pop();
            if (dist[cur] != -1)
            {
                dist[cur] = step;
                que.push(cur + arr[cur]);
                que.push(cur - arr[cur]);
            }
        }
        step++;
    }
    cout << dist[b];
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