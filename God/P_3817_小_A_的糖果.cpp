#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int &i:a){
        cin >> i;
    }

    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        if(a[i]+a[i+1]>x){
            int z = max(0, a[i] + a[i - 1] - x);
            a[i] -= z;
            ans += z;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}