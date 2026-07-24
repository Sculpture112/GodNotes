#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int solve(int n,vector<int>& a,vector<int>& b) {
    int sum = accumulate(b.begin(), b.end(),0);

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, ));

    for (int i = 1; i <= n;i++){
        for (int j = sum; j >= 0;j--){
            if(dp[i-1][j] > a[i]){
                dp[i][j] = dp[i - 1][j];
            }

            if(j>b[i] && )
        }
    }
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
    return 0;
}
