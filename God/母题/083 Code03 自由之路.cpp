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

        int jump1;
    }
    int clock(int i,int v){
        auto &arr = where[v];
        auto it = upper_bound(arr.begin(), arr.end(), i);

        return it == arr.end()?arr[0]:*it;
    }
    int revclock(int i ,int v){
        auto &arr = where[v];
        auto it = 
    }
};