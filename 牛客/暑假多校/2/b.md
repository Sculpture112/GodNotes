# []

> **原题链接:** ()

**涉及知识点:** [[异或线性基]], [[线性基]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin>>n;
    vector<ll>a(n);
    ll s=0;
    for(auto &x:a) {
        cin>>x;
        s^=x;
    }
    ll basis[61] {
    };
    for(ll x:a) {
        x &= ~s;
        for(int b=60;b>=0;--b) if((x>>b)&1) {
            if(!basis[b]) {
                basis[b]=x;
                break;
            }
            x^=basis[b];
        }
    }
    ll best=0;
    for(int b=60;b>=0;--b) best=max(best,best^basis[b]);
    cout << s + 2*best << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--)solve();
}

```

---


