#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    ll power(int x, int n, int mod)
    {
        ll ans = 1;
        while (n > 0)
        {
            if (n & 1)
            {
                ans = (ans * x) % mod;
            }
            x = (x * x) % mod;
            n >>= 1;
        }
        return ans;
    }
    int cuttingBamboo(int n)
    {
        int mod = 1000000007;
        int tail = (n % 3 == 0) ? 1 : (n % 3 == 1 ? 4 : 2);

        int p = ((n % 3 == 0) ? n : n - tail) / 3;
        return power(3, p, mod) * tail % mod;
    }
};