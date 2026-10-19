#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int cnt;
int n;
void dfs(vector<int> &a, int step, int lock, int sum)
{
    if (lock == n && sum == 0)
    {
        cnt++;
        return;
    }

    if (step == 2 * n)
        return;

    dfs(a, step + 1, lock + 1, sum ^ a[step]);
    dfs(a, step + 1, lock, sum);
}

void solve()
{
    cin >> n;
    cnt = 0;
    vector<int> a(2 * n);
    for (int &x : a)
        cin >> x;

    dfs(a, 0, 0, 0);

    if (cnt / n > 1)
    {
        cout << "Menji" << "\n";
    }
    else
    {
        cout << "Bot" << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}