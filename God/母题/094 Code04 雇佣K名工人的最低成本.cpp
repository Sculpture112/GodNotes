#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
class Solution
{
    struct Employee
    {
        double ratio;
        int quality;
        Employee(double r, int q) : ratio(r), quality(q)
        {
        }
    };

public:
    double
    mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        int n = quality.size();

        vector<Employee> employees(n);
        for (int i = 0; i < n; i++) {
            employees.emplace_back(1.0 * wage[i] / quality[i], quality[i]);
        }

        sort(employees.begin(), employees.end(), [](const Employee &a, const Employee &b)
             { return a.ratio < b.ratio; });

        priority_queue<int> heap;

        int ans = INF;
        int sum = 0;
        for (int i = 0, curquality; i < n; i++)
        {
            curquality = employees[i].quality;
            if(heap.size()<k){
                heap.push(curquality);
                sum += curquality;
                if (heap.size() == k)
                {
                    ans = min(ans, sum);
                }
            }
            else{
                if(curquality<)
            }
        }
    }
};