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

        for (int i = 0, status;i<n;i++){
            status = 0;
            for()
        }
    }
};