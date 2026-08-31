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
    map<string, int> rema;
    map<string, int> ans;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        rema[s]++;
    }
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (rema.count(s) && (ans[s]++ == 0))
        {
            cout << "OK" << "\n";
        }

        else if (rema.count(s) && (ans[s]++ != 0))
        {
            cout << "REPEAT" << "\n";
        }
        else
        {
            cout << "WRONG" << "\n";
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