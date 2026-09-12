#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n, s, l;
    cin >> n >> s >> l;

    vector<ll> a(n);
    a[0] = LINF;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
    }

    ll left, right;
    
    left = a[s - 1], right = a[s + 1];
    for (int i = s; i < n;)
    {
        if(left<=right){

        }

    }
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