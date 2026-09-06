#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(400005);
    vector<int> qu(q);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int end = n;
    for (int i = 0; i < q; i++)
    {
        cin >> qu[i];
        int t = end;
        for (int j = 0; j <= t; j++)
        {
            if (a[j] == qu[i])
            {
                swap(a[j], a[end]);
                end++;
            }
        }
    }

    for (int i = 0; i <= end; i++)
    {
        if (a[i] != 0)
        {
            cout << a[i] << " ";
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