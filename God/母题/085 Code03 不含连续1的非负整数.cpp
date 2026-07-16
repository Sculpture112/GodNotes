#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int findIntegers(int n)
    {
        int cnt[31];
        cnt[0] = 1;
        cnt[1] = 2;
        for (int i = 2; i <= 30; i++) {
            cnt[i] = cnt[i - 1] + cnt[i - 2];
        }

        return f(cnt, n, 30);
    }
    int f(int cnt[],int num,int i){
        if(i == -1){
            return 1;
        }
        int ans = 0;
        if((num&(1<<i)) != 0){
            ans += f(cnt, num, i - 1);

            if((num&(1<<(i+1)))!=0)
            {
                return ans;
            }
        }
        ans += f(cnt, num, i - 1);
        return ans;
    }
};
