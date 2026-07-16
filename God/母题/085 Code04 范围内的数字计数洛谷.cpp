#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

ll count(ll num, int d){
    ll ans = 0;
    for (ll tmp = num, right = 1, left, cur; tmp != 0; tmp /= 10,right*=10)
    {
        left = tmp / 10;
        if(d == 0)
            left--;
        ans += left * right;
        cur = tmp % 10;
        if(cur>d){
            ans += right;
        }
        else if(cur == d){
            ans += num % right + 1;
        }
    }
    return ans;
}

ll digitcount(int d, ll a,ll b){
    return count(b, d) - count(a - 1, d);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    ll a, b;
    cin >> a >> b;
    for (int i = 0; i < 9; i++) {
        cout << digitcount(i, a, b)<<" ";
    }
    cout << digitcount(9, a, b) << "\n";
    return 0;
}
