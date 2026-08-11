#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    string n;
    int k;

    cin >> n >> k;
    string ans;
    for (int i = 0; i < n.size(); i++)
    {
        while (!ans.empty() && ans.back() > n[i])
        {
            ans.pop_back();
            k--;
        }
        ans.push_back(n[i]);
    }

    while (k > 0)
    {
        ans.pop_back();
        k--;
    }
    size_t pos = ans.find_first_not_of('0');
    if (pos == string::npos)
    {
        cout << 0 << "\n";
    }
    else
    {
        cout << ans.substr(pos) << "\n";
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