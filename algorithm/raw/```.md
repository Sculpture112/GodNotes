```cpp

```

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,m;cin>>n>>m;
    const int MOD = 1e9 +7;
    vector<vector<long long>> dp(n +1,vector<long long>(m+1,0));

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(i==1||j==1){
                dp[i][j] =1;

            }else{
                dp[i][j]=(dp[i-1][j] + dp[i][j-1])%MOD;
            }
        }
    }
    cout<<dp[n][m]<<endl;
}
// 64 位输出请用 printf("%lld")
```