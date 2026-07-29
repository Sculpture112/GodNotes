#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &cost)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap1;
        priority_queue<int> heap2;
        int n = profits.size();
        for (int i = 0; i < n; i++) {
            heap1.push({cost[i], profits[i]});
        }

        while (k--)
        {
            while(!heap1.empty()&&  heap1.top().first <=w){
                heap2.push(heap1.top().second);
                heap1.pop();
            }
            if(heap2.empty()){
                break;
            }

            w += heap2.top();
            heap2.pop();
        }
        return w;
    }
};
