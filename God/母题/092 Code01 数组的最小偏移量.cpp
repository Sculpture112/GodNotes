#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        multiset<int> set;
        for (int num : nums)
        {
            set.insert(num % 2 == 0 ? num : num * 2);
        }
        int ans = *set.rbegin() - *set.begin();

        while (ans > 0 && *set.rbegin() % 2 == 0)
        {
            int maxvalue = *set.rbegin();
            set.erase(prev(set.end()));
            set.insert(maxvalue / 2);
            ans = min(ans, *set.rbegin() - *set.begin());
        }
        return ans;
    }
};
