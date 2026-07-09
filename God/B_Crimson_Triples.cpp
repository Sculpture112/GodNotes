#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        ll ans = 0;
        for (int b = 1; b <= n;b++){
            ll cnt = n / b;
            ans += cnt * cnt;
        }
        cout << ans << "\n";
    }
    solve();

    return 0;
}