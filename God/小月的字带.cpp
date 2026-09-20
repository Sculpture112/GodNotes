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
    char c;
    cin >> c;
    nt cnt = 0;
    char last = c;
    char ch;
    for (int i = 0; i < n; i++)
    {
        cin >> ch;
        if (ch == last)
        {
            cnt *= 2;
            cnt++;
        }
        else
        {
            cnt *= 2;
        }
    }
    cout << cnt*2;
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