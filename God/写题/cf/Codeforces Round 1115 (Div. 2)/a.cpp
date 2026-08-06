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
    int mx = 0;
    ll ans = 0;
    for(auto num :map){

        if(num.second<=2)
        {
            ans += num.first * num.second;
        }
        else{
            mx = max(mx, num.first);
            ans += num.first * 2;
        }
    }

    if(kinds>1){
        ans += mx;
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