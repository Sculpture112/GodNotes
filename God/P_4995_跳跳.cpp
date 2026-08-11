#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    sort(a.rbegin(), a.rend());
    ll ans = a[0] * a[0];

    for (int k = 1,i=0,j=n-1; k <= n,i<=j; k++) {
        if(k&1 != 0){
            ans += (a[i] - a[j]) * (a[i] - a[j]);
            i++;
        }
        else{
            ans += (a[i] - a[j]) * (a[i] - a[j]);
            j--;
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}