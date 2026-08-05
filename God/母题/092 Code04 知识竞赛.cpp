#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
const int MAXN = 200001;
struct Employee
{
    int a;
    int b;
};

Employee nums[MAXN];
void solve()
{
    sort(nums.begin(), nums.end(), (const Employee &a, const Employee &b) { return abs(a.a - a.b) < abs(b.a - b.b); });
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i].a >> nums[i].b;
    }
    solve;

    return 0;
}
