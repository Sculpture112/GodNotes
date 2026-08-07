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
    vector<int> a(n);
    vector<int> cnt(n + 5);
    int kinds = 0;
    int sim = 0;
    int pre = -1;
    for (int &num : a)
    {
        cin >> num;
        if (pre == num)
            sim++;
        if (cnt[num]++ == 0)
        {
            kinds++;
        }
        pre = num;
    }

    if (kinds == 1)
    {
        cout << 1 << "\n";
        return;
    }

    pre = a[0];
    int sta = 0;
    for (int i = 1; i < n; i++)
    {
        if (sta == 2)
            break;
        if (a[i] == pre && i + 1 < n && a[i + 1] != a[i])
        {
            if (i + 2 < n && a[i + 2] != a[i])
            {
                if (a[i + 1] == a[i + 2])
                {
                    sta = 2;
                }

                else
                    sta = 1;
            }
            else if (i + 1 == n - 1)
            {
                sta = 1;
            }
        }

        pre = a[i];
    }
    if (n >= 4 && a[n - 1] == a[n - 2] && sta != 2 && a[n - 4] != a[n - 1])
    {
        sta = 1;
    }
    int ans = n - sim;
    ans += sta;
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