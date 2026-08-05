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
int n;
int solve()
{
    sort(nums, nums+n, [](const Employee &a, const Employee &b) { return abs(a.a - a.b) < abs(b.a - b.b); });
    int maxa = nums[0].a;
    int maxb = nums[0].b;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if(nums[i].a<nums[i].b){
            ans = max(ans, nums[i].a + maxa);
        }
        else{
            ans = max(ans, nums[i].b + maxb);
        }
        maxa = max(maxa, nums[i].a);
        maxb = max(maxb, nums[i].b);
    }
    return ans;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i].a >> nums[i].b;
    }
    cout<<fixed<<setprecision(1)<<(double)solve()/2;

    return 0;
}
