#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n, x;
    cin >> n >> x;
    int pre = 0;
    vector<int> a(n);
    for(int&x:a){
        cin >> x;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(pre+a[i]>x){
            int s = max(0, pre + a[i] - x);
            a[i] -= s;
            ans += s;
        }
        pre = a[i];
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