#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

vector<int> generate(ll sum,int n,int k){
    bool canSplit(int n, int k);
    bool f(int n, int i, int k, int s, vector<vector<vector<int>>> &dp);
}
vector<int> pick(int n,int k){
    ll sum = 1LL * (n + 1) * n / 2;
    vector<int> ans = generate(sum / 2, n, k);
    if(ans.empty() && (sum&1)){
        ans = generate(sum / 2 + 1, n, k);
    }
    return ans;
}

vector<int> generate(ll sum,int n,int k){
    ll minsum = 1LL * (k + 1) * k / 2;
    ll need = sum - minsum;
    ll range = n - k;
    if(minsum>sum || sum > minsum + range * k){
        return {};
    }

    ll rightsz = need / range;
    ll midindex = k - rightsz + need % range;
    ll leftsz = k - rightsz - (need % range == 0 ? 0 : 1);

    vector<int> ans;
    for (int i = 0; i < leftsz;i++){
        ans[i] = i + 1;
    }
    ans[leftsz] = midindex;
    for (int i = k - 1, j = 0; j < rightsz;j++,i--){
        ans[i] = n - j;
    }
    return ans;
}