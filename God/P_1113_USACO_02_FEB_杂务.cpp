#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int MAXN = 100001;
vector<vector<pair<int,int>>> graph(MAXN);
int indegree[MAXN];
void solve()
{
    int n;
    cin >> n;
    while (n--)
    {

        int u;
        int w;
        cin >> u >> w;
        int x;
        cin >> x;

        while (x > 0)
        {
            graph[x].push_back({w,x});
            indegree[u]++;
            cin >> x;
        }

        vector<pair<int, int>> queue;
        int l = 0, r = 0;
        for (int i = 1; i <= n;i++){
            if(indegree[i] == 0)
            {
                queue[r++] = {};
            }
        }

        while(l<r){
            int cur = queue[l++];

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