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

    int step = 0;
    vector<int> dist(n, -1);
    while (!que.empty())
    {
        int cur = que.front();
        que.pop();
        if(dist[cur] != -1){
            que.push(arr[cur] + cur);
            que.push(arr[cur])
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