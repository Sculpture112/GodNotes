#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int countSpecialNumbers(int n)
    {
        int len = 1;
        int offset = 1;
        int tmp = n / 10;
        while (tmp > 0)
        {
            offset *= 10;
            len++;
            tmp /= 10;
        }

        vector<int> cnt(len, 0);
        cnt[0] = 1;
        for (int i = 1, k = 10 - len + 1; i < len; k++, i++)
        {
            cnt[i] = cnt[i - 1] * k;
        }

        int ans = 0;
        if (len >= 2)
        {
            ans = 9;
            for (int i = 2, a = 9, b = 9; i < len; i++, b--)
            {
                a *= b;
                ans += a;
            }
        }

        int first = n / offset;
        ans += (first - 1) * cnt[len - 1];

        ans += f(cnt, len - 1, offset / 10, n, 1 << first);
        return ans;
    }
    int f(vector<int> &cnt, int len, int offset, int n, int status)
    {
        if (len == 0)
            return 1;

        int ans = 0;
        int first = n / offset % 10;
        for (int i = 0; i < first; i++)
        {
            if (((1 << i) & status) == 0)
            {
                ans += cnt[len - 1];
            }
        }
        if (((1 << first) & status) == 0)
        {
            ans += f(cnt, len - 1, offset/10, n, status | (1 << first));
        }
        return ans;
    }
};