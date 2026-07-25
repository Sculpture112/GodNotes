#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
vector<int> a;
const int MAXN = 2e5;
int dp[MAXN];
int n;
int f(int sum,int i,int cnt)
{
    if(i == n-1)
        return cnt;
    if(a[i]>=0){
        cnt++;
        sum += a[i];
        return cnt;
    }
    int p1 = INT_MIN;
    if(sum+a[i]>=0){
        p1 = f(sum+a[i], i+1, cnt+1);
    }
    cnt = max(p1, f(sum, i + 1, cnt));
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> ans(n);
    cout << f(0, 0, 0);
    return 0;
}