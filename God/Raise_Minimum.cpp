#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using i128 = __int128_t;

bool ok(vector<ll>& A,ll k,i128 x){
    i128 need = 0;
    ll n = A.size();

    for (int idx = 0; idx < n;idx++){
        int i = idx + 1;

        if(A[idx] < x){
            i128 diff = x - A[idx];
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
    ll k;
    cin >> n >> k;
    vector<ll> A(n);
    ll mn = LLONG_MAX;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        mn = min(mn, A[i]);
    }

    i128 left = mn, right = (i128)mn + (i128)n * k + 1;

    while(right - left >1){
        i128 mid = (left - right) / 2 + right;
        if(ok(A,k,mid)){
            left = mid;
        }
        else{
            right = mid;
        }
    }
    cout << (ll)left;

    return 0;
}