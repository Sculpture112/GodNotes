#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int makepal(ll x,bool odd){
    if(odd){
        x /= 10;
    }

    ll result = x;
    
    while(x!=0){
        result = result * 10 +  x % 10;
        x /= 10;
    }
    return result;
}
void solve() {
    int n;
    cin >> n;

    if(n<=12){
        cout << -1 << "\n";
        return;
    }

    for (int half = 2; half < n;half++){
        ll even = makepal(half, false);
        ll odd = makepal(half, true);

        if(even>)
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}