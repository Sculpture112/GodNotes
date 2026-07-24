#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int solve(int n,vector<int>& a,vector<int>& b) {
    int sum = accumulate(b.begin(), b.end(),0);

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, INT_MIN));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= 0;j--){
            if(dp[i-1][j] >= a[i]){
                dp[i][j] = dp[i - 1][j];
            }

            if(j>=b[i] && dp[i-1][j-b[i]]!=INT_MIN)
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j - b[i]] + a[i]);
            }
        }
    }

    for (int j = 0; j <= sum;j++){
        if(dp[n][j] != INT_MIN){
            return j;
        }
    }
    return -1;
}

int solve2(int n,vector<int>& a,vector<int>& b){
    int m = accumulate(b.begin(), b.end(), 0);
    vector<int> dp(m + 1, INT_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0;j--){

            int cur = INT_MIN;
            if(dp[j] >= a[i])
                cur = dp[j];
            if (j >= b[i] && dp[j - b[i]] != INT_MIN)
            {
                cur = max(cur, dp[j - b[i]] + a[i]);
            }
            dp[j] = cur;
        }
    }
    for (int j = 0; j <= m;j++){
        if(dp[j] != INT_MIN)
            return j;
    }
    return -1;
}

int solve3(int n,vector<int>& a,vector<int>& b){
    int m = accumulate(a.begin(), a.end(), 0);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
    //dp[i][j] == 到了i个之后的j能力最小需要花费多少钱
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m;j++){
            if(j >= a[i] && dp[i-1][j] != INT_MAX){
                dp[i][j] = dp[i - 1][j];
            }
            if(j>=a[i] && dp[i-1][j-a[i]] !=INT_MAX){
                dp[i][j] = min(dp[i][j],dp[i - 1][j - a[i]] + b[i]);
            }
        }
    }

    int ans = *min_element(dp[n].begin(), dp[n].end());
    return ans == INT_MAX ? -1 : ans;
}
int solve4(int n,vector<int>& a,vector<int>& b){
    int m = accumulate(a.begin(), a.end(), 0);
    vector<int> dp(m + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 0; j <= m;j++){
            int cur = INT_MAX;
            if (j >= a[i] && dp[j] != INT_MAX)
            {
                cur = dp[j];
            }
            if(j>=a[i] && dp[j-a[i]]!=INT_MAX){
                cur = min(cur, dp[j - a[i]] + b[i]);
            }
            dp[j] = cur;
        }
    }

    int ans = *min_element()
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    cout << solve3(n, a, b);
    return 0;
}
