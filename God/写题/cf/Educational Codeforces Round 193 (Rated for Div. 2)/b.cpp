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
    for (int &x : a)
        cin >> x;
    vector<int> color, cnt;

    for (int x : a)
    {
        if (!color.empty() && color.back() == x)
        {
            cnt.back()++;
        }
        else
        {
            color.push_back(x);
            cnt.push_back(1);
        }
    }

    int m = color.size();

    int ans = m;

    for (int i = 0; i + 1 < m; i++)
    {
        if (cnt[i] >= 2 && cnt[i + 1] >= 2)
        {
            ans = max(ans, m + 2);
            break;
        }

        if (cnt[i] >= 2 && (i + 2 == m || color[i + 2] != color[i]))
        {
            ans = max(ans, m + 1);
            continue;
        }

        if (cnt[i + 1] >= 2 && (i == 0 || color[i - 1] != color[i + 1]))
        {
            ans = max(ans, m + 1);
            continue;
        }
    }

    for (int i = 0; i + 2 < m; i++)
    {
        if (cnt[i + 2] >= 2 && cnt[i] >= 2 && color[i] != color[i + 2])
        {
            ans = max(ans, m + 1);
            break;
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