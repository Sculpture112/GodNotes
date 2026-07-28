#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size();
        int sum = 0;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            sum += costs[i][0];
            arr[i] = costs[i][1] - costs[i][0];
        }

        sort(arr.begin(), arr.end());
        for (int i = 0; i < n / 2;i++){
            sum += arr[i];
        }
        return sum;
    }
};
