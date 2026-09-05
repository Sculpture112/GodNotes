#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0, t = 1, cnt = 0; i < n; i++, t++)
    {
        if (s[i] == '1')
        {
            cnt++;
        }
        // cout << t;
        if (t == k)
        {
            // cout << 1;
            if (cnt == k)
            {
                ans++;
            }
            cnt = 0;
            t = t % k;
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