#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, m;
    cin >> n >> m;
    map<int, int> a, b, c;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        b[x]++;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        c[x]++;
    }

    auto ita = a.begin();
    auto itb = b.begin();
    auto itc = c.begin();
    int cur = ita->first * itb->first * itc->first;
    int cnt = ita->second * itb->second * itc->second;
    cnt = min(cnt, m);
    m -= cnt;
    for (int i = 0; i < cnt; i++)
    {
        cout << cur << " ";
    }
    for (int i = 0; i < n; i++)
    {
        if (m<=0)
            break;

        

        int nxt = min({ita++->first, itb->first, itc->first});



        cur = ita->first * itb->first * itc->first;

        cout << cur;
        cnt = ita->second * itb->second * itc->second;
        cnt = min(cnt, m);
        m -= cnt;
        for (int i = 0; i < cnt; i++)
        {
            cout << cur << " ";
        }
    }
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