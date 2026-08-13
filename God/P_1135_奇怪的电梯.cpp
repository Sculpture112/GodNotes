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

    vector<int> dist(n, -1);
    dist[a] = 0;
    while (!que.empty())
    {
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            int cur = que.front();
            que.pop();

            int next1 = cur + arr[cur];
            int next2 = cur - arr[cur];
            if(next1>=0 && next1<n && dist[next1] == -1){
                dist[next1] = dist[cur] + 1;
                que.push(next1);
            }
            if(next2>=0 && next2<n && dist[next2] == -1){
                dist[next2] = dist[cur] + 1;
                que.push(next2);
            }

        }
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