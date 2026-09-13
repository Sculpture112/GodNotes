#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll mx = -INF;
    int last = INF;
    int dis = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (mx < a[i])
        {
            // cout << "Yes";
            mx = max(mx, a[i]);
            dis = max(dis, i - last);
            last = i;
            cnt++;
        }
    }

    if (cnt < 2)
    {
        cout << 1 << " " << 0;
        return;
    }
    cout << cnt << " " << dis;
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