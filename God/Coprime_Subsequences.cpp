#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1000000007;

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> freq(n + 1,0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n;j+=i){
            cnt[i] += freq[j];
        }
    }

    vector<int> pow2(n + 1, 2);
    for (int i = 2; i <= n; i++) {
        pow2[i] = pow2[i - 1] * 2 % MOD;
    }

    vector<ll> f(n + 1, 0);
    for (int i = n; i > 0; i--)
    {
        f[i] = pow2[i] - 1;
        for (int j = 2 * i; j <= n; j+=i) {
            f[i] = (f[i] - f[j]) % MOD;
        }
    }
    cout << f[1];


    return 0;
}