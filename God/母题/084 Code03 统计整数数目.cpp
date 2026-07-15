#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    const int MOD = 1e9 + 7;
    string num;
    int dp[23][401][2];
    int minsum, maxsum, len;

    void build()
    {
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < maxsum; j++) {
                dp[i][j][0] = -1;
                dp[i][j][1] = -1;
            }
        }
    }
    
    int count(string num1, string num2, int min_sum, int max_sum)
    {
        minsum = min_sum;
        maxsum = max_sum;
        num = num2;
        len = num.size();
        build();
        int ans = f(0, 0, 0);
        num = num2;
        len = num.size();
        build();
        ans = (ans + f(0, 0, 0)) % MOD;
        if(check()){
            ans = (ans + 1) % MOD;
        }
        return ans;
    }
    int f(int sum,int free,int i){
        if(sum>maxsum){
            return 0;
        }
        if(sum + (len - i)*9<minsum){
            return 0;
        }

        if(i == len)
            return 1;

        if(dp[i][sum][free] != -1){
            return dp[i][sum][free];
        }

        int cur = num[i]-'0';
        int ans = 0;
        if(free == 0){
            for (int pick = 0;pick<cur;pick++){
                ans += (ans + f(sum + pick, 1, i + 1))%MOD;
                
            }
            ans += (ans +f(sum + cur, 0, i + 1))%MOD;
        }
        else{
            for (int pick = 0; pick <= 9;pick++){
                ans += (ans + f(sum + pick, 1, i + 1)) % MOD;
            }
        }
        dp[i][sum][free] = ans;
        return ans;
    }
    bool check(){
        int sum = 0;

        for(char cha:num){
            sum += cha - '0';
        }
        return sum <= maxsum && sum >= minsum;
    }
};