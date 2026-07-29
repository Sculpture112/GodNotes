#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

ll power(ll x,int n,int mod){
    ll ans = 1;
    while(n>0){
        if(n&1){
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        n >>= 1;
    }
    return ans;
}
int maxValue2(int n, int k)
{
    int mod = 1000000007;
    ll a = n / k;
    ll b = n % k;
    ll part1 = power(a + 1, b, mod);
    ll part2 = power(a, k - b, mod);
    return part1 * part2 % mod;
}
