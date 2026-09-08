#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    ll x, y, k;
    cin >> x >> y >> k;

    ll ans = 0;

    int diff = y - x;
    int cnt = 0;
    while(y-x!=diff){
        ans += y % x;
        cnt++;
        y++, x++;
        if(cnt==k)
            break;
    }
    for (cnt = 0; cnt < k; cnt++) {
        
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}