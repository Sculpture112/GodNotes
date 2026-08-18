#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;
const int MOD = 998244353;
#define all(x) (x).begin(), (x).end()
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    unordered_map<char, int> cnt;
    int size = 0;
    for(char&c:s){
        if(cnt[c]++ == 0){
            size++;
        }
    }
    int ans = 1;
    for(auto[_,count] : cnt){
        if(count >1){
            ans *= count;
        }
    }

    ans *= (size) * (size - 1);
    cout << ans % MOD;
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