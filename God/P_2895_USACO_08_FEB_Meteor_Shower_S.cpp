#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 305;
const int INF = 0x3f3f3f3f;

const ll LINF = 4e18;
int dangertime[N][N];
int dist[N][N];

#define all(x) (x).begin(), (x).end()
int graph[301][301];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void solve()
{
    int n;
    cin >> n;
    memset(dangertime, 0x3f, sizeof dangertime);
    memset(dist, -1, sizeof dist);

    for (int i = 0; i < n; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + x;
            int ny = dy[i] + y;

            if (nx >= 0 && nx <= n && ny >= 0 && ny <= n)
            {
                dangertime[nx][ny] = min(dangertime[nx][ny], t);
            }
        }
    }

    if(dangertime[0][0] == 0){
        cout << -1 << "\n";
        return;
    }

    queue<pair<int, int>> q;
    q.push({0,0});
    dist[0][0] = 0;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        if(dangertime[x][y] == INF){
            cout << dist[x][y] << "\n";
            return;
        }

        for (int j = 0; j < 4; j++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx<0 || nx >n ||ny<0 || ny>n){
                continue;
            }               


            if(dist[nx][ny] !=)
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