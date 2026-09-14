#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100010;
ll a[N], diff[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (m--)
    {

        int l, r;
        cin >> l >> r;
        if (l == r)
        {
            diff[l] += 1;
            diff[l + 1] -= 2;
            diff[l + 2] += 1;
        }
        else if (r == l + 1)
        {
            diff[l] += 1;
            diff[l + 1] -= 1;
            diff[l + 2] -= 1;
            diff[l + 3] += 1;
        }
        else if ((r - l + 1) & 1)
        {
            int mid = (l + r) / 2;
            diff[l] += 1;
            diff[mid + 1] -= 2;
            diff[r + 1] += 1;
        }
        else
        {
            int mid = (l + r) / 2;
            diff[l] += 1;
            diff[mid + 1] -= 1;
            diff[mid + 2] -= 1;
            diff[r + 1] += 1;
        }
    }
    // 两次前缀和还原增量
    for (int i = 1; i <= n; i++)
        diff[i] += diff[i - 1];
    for (int i = 1; i <= n; i++)
        diff[i] += diff[i - 1];
    for (int i = 1; i <= n; i++)
        cout << a[i] + diff[i] << " \n"[i == n];
    return 0;
}