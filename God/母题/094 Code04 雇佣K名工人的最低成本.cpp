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
            employees.emplace(1.0 * wage[i] / quality[i], quality[i]);
        }
        
    }
};