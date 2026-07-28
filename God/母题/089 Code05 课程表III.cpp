#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        sort(courses.begin(), courses.end(), [](const auto &a, const auto &b)
             { return a[1] < b[1]; });

        int time = 0;
        priority_queue<int> heap;
        for (auto &c : courses)
        {
            if(time + c[0]<=c[1]){
                heap.push(c[0]);
                time += c[0];
            }
            else{
                if(!heap.empty() && heap.top()>c[0]){
                    heap.push(c[0]);
                    time += c[0];
                    time -= heap.top();
                    heap.pop();
                }
            }
        }
        return heap.size();
    }
};