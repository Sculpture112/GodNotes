# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
void solve() {
    int n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for(auto&x:a)cin>>x;
    sort(a.begin(),a.end());
    vector<ll>pre(n+1);
    for(int i=0;i<n;i++)pre[i+1]=pre[i]+a[i];
    ll base=pre[n],best=LLONG_MIN;
    if(k&1) {
        int m=k/2;
        for(int idx=m;idx+m<n;idx++) {
            ll old=pre[m]+(pre[idx+m+1]-pre[idx+1]);
            ll nw=1LL*(k-1)*a[idx];
            best=max(best,nw-old);
        }
    }else {
        int m=k/2;
        for(int j=m;j+m<=n;j++) {
            ll old=pre[m-1]+a[j-1]+(pre[j+m]-pre[j]);
            ll nw=1LL*m*(a[j-1]+a[j]);
            best=max(best,nw-old);
        }
    }
    cout<<base+best<<'\n';
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


