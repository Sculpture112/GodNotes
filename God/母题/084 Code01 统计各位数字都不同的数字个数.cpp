#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {
        if(n == 0){
            return 1;
        }

        int ans = 10;
        for (int s = 9, i = 9, k = 2; k <= n;k++,i--){
            s *= i;
            ans += s;
        }
        return ans;
    }
};