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

    int singlecnt[3] = {0};
    int cnt[3] = {0};
    int u;
    for (int i = 0; i < n; i++)
    {
        int ct = 0;
        int idx = 0;
        for (int j = 0; j < 3; j++)
        {
            cin >> u;
            if (u == 1)
            {
                cnt[j]++;
                ct++;
                idx = j;
            }
        }

        if (ct == 1)
            singlecnt[idx]++;
    }

    bool sign = true;
    for (int i = 0; i < 3; i++)
    {
        if (singlecnt[i] == 0)
        {
            sign = false;
        }
    }

    if (sign)
    {
        cout << 3 << "\n";
        return;
    }

    for (int i = 0; i < 3; i++)
    {

        if (cnt[i] == n)
        {
            cout << 1 << "\n";
            return;
        }
    }

    cout << 2 << "\n";
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