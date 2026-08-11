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
    vector<string> a(n);
    for (string &x : a)
        cin >> x;
    sort(a.begin(), a.end(), [](const auto &a, const auto &b)
         { return a > b; });
    string ans = "";
    for(string &x:a){
        ans += x;
    }
    cout << ans;
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