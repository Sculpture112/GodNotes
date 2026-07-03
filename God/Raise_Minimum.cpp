#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using i128 = __int128_t;

bool ok(vector<ll>& A,i128 k,ll x){
    ll need = 0;
    ll n = A.size();

    for (int idx = 0; idx < n;idx++){
        int i = idx + 1;

        if(A[idx] < x){
            ll diff = x - A[idx];
            need += (diff + i - 1) / i;

            if(need > k){
                return false;
            }
        }
    }
    return need <= k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    i128 k;
    cin >> n >> k;
    vector<ll> A(n);
    ll mn = LONG_LONG_MAX;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        mn = min(mn, A[i]);
    }

    ll left = mn, right = mn + n * k + 1;

    while(right - left >1){
        ll mid = (left - right) / 2 + right;
        if(ok(A,k,mid)){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    cout << left;

    return 0;
}