#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    int i = 1;
    for(auto &x:a){
        cin >> x.first;
        x.second = i++;
    }

    sort(a.begin(), a.end(), [](const auto &a, const auto &b)
         { return a.first < b.first; });

    double ans = 0;
    for(auto& x:a){
        cout << x.second << " ";
        ans += x.first;
    }
    ans -= a[n - 1].first;
    ans /= n;
    cout << "\n";
    cout << fixed << setprecision(2) << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}