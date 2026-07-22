#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;
const int MAXN = 100001;
int nums[MAXN], dp[MAXN], endsArr[MAXN], ans[MAXN];
int n, k;
#define all(x) (x).begin(), (x).end()

int bs(int len,int num){
    int l = 0, r = len - 1, ans = -1,m;
    while(l<=r){
        m = (l - r) / 2 + r;
        if(endsArr[m] <= num){
            ans = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return ans;
}

int filldp(){
    int len = 0;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }



    return 0;
}
