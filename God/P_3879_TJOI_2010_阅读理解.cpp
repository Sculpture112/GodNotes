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
    vector<unordered_map<string, int>> map(n);

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            string s;
            cin >> s;
            map[i][s]++;
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if(map[i].count(s)){
                cout << i+1 << " ";
            }
        }
        cout << "\n";
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