#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int one = 0;
    int ten = 0;
    int bai = 0;
    for (int num : a)
    {
        int qian = num % 10000 / 1000;

        num = num % 10000;
        qian++;
        qian = qian * 1000;
        int t = qian - num;
        one += (t % 10);
        ten += (t % 100 / 10);
        bai += (t % 1000 / 100);
        // one += ((num % 10 == 0) ? 0 : (10 - num % 10));
        // ten += ((num % 100 / 10 == 0) ? 0 : (10 - num % 100 / 10));

        // bai += ((num % 1000 / 100 == 0) ? 0 : (10 - num % 1000 / 100));
    }

    cout << one << " " << ten << " " << bai;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    // }

    // int one = 0;
    // int ten = 0;
    // int bai = 0;

    // for (string num : a)
    // {
    //     one += ((10 - num[num.size() - 1] + '0') == 0 ? 0 : 10 - num[num.size() - 1] + '0');
    //     if (num.size() >= 2)
    //     {
    //         ten += ((10 - num[num.size() - 2] + '0') == 0 ? 0 : 10 - num[num.size() - 2] + '0');
    //     }
    //     if (num.length() >= 3)
    //     {
    //         bai += ((10 - num[num.size() - 3] + '0') == 0 ? 0 : 10 - num[num.size() - 3] + '0');
    //     }
    // }
    // cout << one << " " << ten << " " << ten;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}