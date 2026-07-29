#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        int n = events.size();
        sort(events.begin(), events.end(), [](const auto &a, const auto &b)
             { return a[0] < b[0]; });

        int minday = events[0][0];
        int maxday = events[0][1];
        for (int i = 1; i < n; i++) {
            maxday = max(maxday, events[i][1]);
        }

        priority_queue<int, vector<int>, greater<int>> heap;

        int ans = 0;
        for (int day = minday, i = 0; day <= maxday; day++)
        {
            while (i < n&&events[i][0]==day){
                heap.push(events[i++][1]);
            }
            while(!heap.empty() && heap.top()<day){
                heap.pop();
            }
            if(!heap.empty()){
                heap.pop();
                ans++;
            }
        }
        return ans;
    }
};
