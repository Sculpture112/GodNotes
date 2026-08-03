#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        sort(answers.begin(), answers.end());
        int ans = 0;

        for (int i = 0, j = 1; i < answers.size();j++){
            int x = answers[i];
            while(j<answers.size() && answers[j] == answers[i]){
                j++;
            }
            ans += (j - i + x) / (x + 1) * (x + 1);
            i = j;
        }
        return ans;
    }
};
