#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;
const int MAXN = 1001;
#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    cin >> n;


    map<int, int> map;
    int kinds = 0;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        if(map[value]++ ==0){
            kinds++;
        }
    }
    ll ans = 0;
    int mx = 0;
    int mxcount = 0;
    for(auto num:map){
        if(num.second - 1<=n-num.second){
            ans += num.first * num.second;
        }
        else{
            ans += num.first * (n - num.second);
            if(num.first>mx){
                mx = num.first;
                mxcount = num.second-(n-num.second);
            }
        }
    }
    if(mx!=0){
        ans += mxcount <= 2 ? mx * mxcount : mx * 2;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}