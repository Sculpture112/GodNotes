#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        int n = req_skills.size();
        int m = people.size();
        unordered_map<string, int> map;
        int cnt = 0;
        for(string& s : req_skills){
            map[s] = cnt++;
        }

        vector<int> arr(m);
        for (int i = 0, status; i < n; i++)
        {
            status = 0;
            for(auto& skill : people[i]){
                if(map.count(skill))
                    status |= (1 << map[skill]);
            }
            arr[i] = status;
        }

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        int sz = f(arr, n, m, 1, 0, dp);

        
    }
    int f(vector<int>& arr,int n,int m,int i,int s,vector<vector<int>>& dp){
        if(s == (1<<n) -1){
            return 0;
        }
        if(i == m){
            return INF;
        }

        if(dp[i][s]!=-1){
            return dp[i][s];
        }

        int p1 = f(arr, n, m, i + 1, s, dp);
        int p2 = INF;
        int next = INF;
        next = f(arr, n, m, i + 1, s |= arr[i], dp);
        if(next != INF){
            p2 = 1 + next;
        }
        dp[i][s] = min(p1, p2);
        return dp[i][s];
    }
};