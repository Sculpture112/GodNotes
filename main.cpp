#include <bits/stdc++.h>
using namespace std;
int main(){ios::sync_with_stdio(false);cin.tie(nullptr);int T;cin>>T;while(T--){int n,m;cin>>n>>m;vector<int> f(m+2), ge(m+3);for(int i=0,a;i<n;i++){cin>>a; ++f[a];}for(int x=m;x>=1;--x) ge[x]=ge[x+1]+f[x];int ans=0;for(int x=1;x<=m;++x){int cur=ge[x]; if(2*x<=m) cur+=f[2*x]; ans=max(ans,cur);}cout<<ans<<'\n';}}
