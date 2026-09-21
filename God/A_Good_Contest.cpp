#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    int mn = INF;
    for(int i= 0,u;i<3;i++){
        cin >> u;
        mn = min(mn, u);
    }
    // cout << n << " " << mn << "\n";
    cout << n - mn << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}