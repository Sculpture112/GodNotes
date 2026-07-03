#include <bits/stdc++.h>
using namespace std;
int v[4];
int n;
using ll = long long;
const int MAXN = 100005;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 4; i++)
    {
        cin >> v[i];
    }

    vector<ll> f(MAXN, 0); // 每个硬币无限次凑出j的方案数
    f[0] = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = v[i]; j < MAXN; j++)
        {
            f[j] += f[j - v[i]];
        }
    }

    cin >> n;
    while (n--)
    {
        int c[4];
        for (int i = 0; i < 4; i++)
        {
            cin >> c[i];
        }
        int s;
        cin >> s;

        int rest = s;

        ll ans = 0;
        for (int mask = 0; mask < 16; mask++)
        {

            int cnt = 0;
            for (int i = 0; i < 4; i++)
            {

                if (mask & (1 << i) != 0)
                {
                    rest -= (c[i] + 1) * v[i];
                    cnt++;
                }
            }

            if (rest < 0)
            {
                continue;
            }

            if(cnt %2 ==0){
                ans += f[rest];
            }
            else{
                ans -= f[rest];
            }
        }
    }

    return 0;
}