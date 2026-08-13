#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int N = 24;
vector<bool> IsPrime(300, true);

int n, k;
int ans = 0;
vector<int> arr(N);
void init()
{
    IsPrime[0] = false, IsPrime[1] = false;
    for (int i = 2; 1ll * i * i <= N; i++)
    {
        if (!IsPrime[i])
            continue;
        for (int j = i * i; j <= N; j += i)
        {
            IsPrime[j] = false;
        }
    }
}
void dfs(int idx, int select, int sum)
{
    if (select == k )
    {
        if(IsPrime[sum]){
            ans++;
        }
        return;
    }

    if (idx == n)
        return;

    dfs(idx + 1, select + 1, sum + arr[idx]);
    dfs(idx + 1, select, sum);
}
void solve()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    init();
    dfs(0, 0, 0);
    cout << ans;
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