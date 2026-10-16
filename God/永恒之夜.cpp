#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, r;
    cin >> n >> r;

    vector<vector<double>> dist(n, vector<double>(n, LINF));

    vector<int> x(n), y(n);
    vector<string> name(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> name[i];
    }

    auto dis = [&](int i, int j)
    {
        int dx = x[i] - x[j];
        int dy = y[i] - y[j];
        return dx * dx + dy * dy;
    };

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = dis(i, j);
        }
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i==j)continue;
            if (dist[i][j] <= r)
            {
                ans[i]++;
            }
        }
    }

    int min = *min_element(ans.begin(), ans.end());

    vector<string> as;
    for (int i = 0; i < n; i++) {
        if(min == ans[i]){
            as.push_back(name[i]);
        }
    }

    for(string s:as)
        cout << s << "\n";

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