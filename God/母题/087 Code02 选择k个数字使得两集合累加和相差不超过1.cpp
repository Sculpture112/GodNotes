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

