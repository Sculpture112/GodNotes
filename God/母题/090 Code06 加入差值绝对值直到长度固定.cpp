#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int len2(vector<int> &arr)
{
    int g = 0;
    int maxvalue = 0;
    for (int num : arr)
    {
        maxvalue = max(maxvalue, num);
        if (num != 0)
        {
            g = num;
        }
    }

    if (g == 0)
        return arr.size();
    unordered_map<int, int> cnt;
    for (int num : arr)
    {
        if (num != 0)
        {
            g = gcd(g, num);
        }
        cnt[num]++;
    }

    int ans = maxvalue / g;
    int maxcnt = 0;
    for (auto [num, value] : cnt)
    {
        if (num != 0)
            ans += value - 1;
        maxcnt = max(maxcnt, value);
    }

    ans += cnt.count(0) ? cnt[0] : (maxcnt > 1 ? 1 : 0);
    return ans;
}
