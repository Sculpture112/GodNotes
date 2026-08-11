#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int sum, n;
    cin >> sum >> n;
    vector<int> a(n);
    for(int&x:a)
        cin >> x;
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0, j = n - 1; i < n, i <= j;)
    {
        if(a[i]+a[j]<=sum){
            ans++;
            i++;
            j--;
        }
        else{
            ans++;
            j--;
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