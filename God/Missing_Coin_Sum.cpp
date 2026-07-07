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
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll ans = 1;
    sort(a.begin(), a.end());
    for(int x : a){
        if(ans<x){
            break;
        }
        ans += x;
    }
    cout << ans;
    return 0;
}