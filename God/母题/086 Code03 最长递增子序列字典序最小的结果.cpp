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
    for (int i = n - 1, find; i >= 0; i--)
    {
        find = bs(len, nums[i]);
        if(find == -1){
            endsArr[len++] = nums[i];
            dp[i] = len;
        }
        else{
            endsArr[find] = nums[i];
            dp[i] = find + 1;
        }
    }
    return len;
}

void lis(){
    k = filldp();
    fill(ans, ans + k, INF);
    for (int i = 0; i < n; i++) {
        if(dp[i] = k){
            ans[0] = nums[i];
        }
        else if(ans[k-dp[i]-1]<nums[i]){
            ans[k - dp[i]] = nums[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // cin >> T;

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    lis();
    for (int i = 0; i < k-1; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[k - 1];

    return 0;
}
