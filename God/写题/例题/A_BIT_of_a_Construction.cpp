#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        ll x = 1;
        if(n == 1){
            cout << k << "\n";
            continue;
        }
        while (x * 2 - 1 <= k)
        {
            x <<= 1;
        }

        ll first = x - 1;
        ll second = k - first;

        cout<<first<<" "<<second;
        for (int i = 3; i <= n;i++){
            cout << " " << 0;
        }
        cout << "\n";
    }

    solve();

    return 0;
}