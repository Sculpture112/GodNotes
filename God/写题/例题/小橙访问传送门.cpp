#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> r(n),b(m);
    int y = INF, x = INF;
    for (int i = 0; i < n; i++) {
        cin >> r[i];
        x = min(x, abs(r[i]));
    }
    int mn = INF;
    sort(r.begin(), r.end());
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        auto it = lower_bound(r.begin(), r.end(), b[i]);
        if (it != r.end())
        {
            mn = min(mn, abs(*it - b[i]));
        }

        if (it != r.begin())
        {
            --it;
            mn = min(mn, abs(*it - b[i]));
        }
        y = min(y, abs(b[i]));
        
    }

    cout << x + y + mn;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}