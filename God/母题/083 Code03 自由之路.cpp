#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int n, m;
    vector<vector<int>> dp;
    vector<vector<int>> where;
    string r, k;
    int findRotateSteps(string ring, string key)
    {
        n = ring.size();
        m = key.size();
        r = ring;
        k = key;

        where.assign(26, {});
        for (int i = 0; i < n; i++)
        {
            where[ring[i] - 'a'].push_back(i);
        }

        dp.assign(n, vector<int>(m, -1));

        return f(0, 0);
    }
    int f(int i ,int j){
        if(j == m){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(r[i] == k[j]){
            return dp[i][j] = 1 + f(i,j+1);
        }

        int v = k[j] - 'a';
        int jump1 = clock(i,v);
        int distance1 = jump1 > i ? jump1 - i : n - i + jump1;
        int jump2 = revclock(i, v);
        int distance2 = jump2 < i ? i - jump2 : i + n - jump2;
        return dp[i][j] = min(distance1 + f(jump1, j), distance2 + f(jump2, j));
    }
    int clock(int i,int v){
        auto &arr = where[v];
        auto it = upper_bound(arr.begin(), arr.end(), i);

        return it == arr.end()?arr[0]:*it;
    }
    int revclock(int i ,int v){
        auto &arr = where[v];
        auto it = lower_bound(arr.begin(), arr.end(), i);
        return it == arr.begin() ? arr.back() : *(it - 1);
    }
};