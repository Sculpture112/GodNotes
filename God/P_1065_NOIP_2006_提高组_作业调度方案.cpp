#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int m, n;
    cin >> m >> n;

    vector<int> shunxu(2 * n);
    vector<int> gongxu[n];

    for (int i = 0; i < 2 * n; i++)
    {
        cin >> shunxu[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0, v; j < m; j++)
        {
            cin >> v;
            gongxu[i].push_back(v);
        }
    }

    vector<int> time[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int v;
            cin >> v;
            time[i].push_back(v);
        }
    }

    vector<int> path[m];
    vector<int> used(n);
    for (int i = 0; i < m; i++) {
        path[i].resize(100);
    }
    for (int i = 0; i < 2 * n; i++)
    {
        int order = shunxu[i]; // 工件号
        int machine = gongxu[order][used[order]];

        int t = used[order]++;
        auto it = find(path[machine].begin(), path[machine].end(), 0);

        if (it != path[machine].end() && it + t < path[machine].end())
        {
            for (int k = 0; k < t; k++)
            {
                path[machine][it] = order;
            }
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