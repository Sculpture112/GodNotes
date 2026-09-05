#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;
    int cnt[3]={};
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i]%2 == 0){
            if((a[i]/2) %2 == 0){
                cnt[0]++;
            }
            else{
                cnt[1]++;
            }
        }
        else{
            cnt[2]++;
        }
    }
    // int mx = 0;
    // for (int i = 0; i < 3; i++) {
    //     cout << cnt[i] << " ";
    // }
    // cout << "\n";
    // for(int num:cnt){
    //     mx = max(mx, num);
    // }
    // cout << mx << "\n";

    int ans = 0;
    for(int num:cnt){
        ans = max(ans, num);
    }
    cout << ans<<"\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}