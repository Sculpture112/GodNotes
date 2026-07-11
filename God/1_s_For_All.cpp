#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int sum(int x){
    int ans = 0;
    while(x!=0){
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
void solve() {
    int n;
    cin >> n;
    if(n%10==0){
        cout << n / 5 + 5;
    }
    else{
        cout << sum(n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}