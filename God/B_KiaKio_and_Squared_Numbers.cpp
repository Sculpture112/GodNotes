#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

ll upgrade(int x){
    ll sum = 0;
    while(x>0){
        sum += (x % 10) * (x % 10);
        x /= 10;
    }
    return sum;
}
ll C2(int x){
    if(x<2)
        return 0;
    return x * (x - 1) / 2;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int&x:a)
        cin >> x;

    for (int i = 0; i < 100;i++){
        for (int i = 0; i < n;i++){
            a[i] = upgrade(a[i]);
        }
    }
    unordered_map<int,int> cnt;
    for (int i = 0; i < n;i++){
        cnt[a[i]]++;
    }

    ll ans = 0;
    for(auto[_,cn]:cnt){
        ans += C2(cn);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}