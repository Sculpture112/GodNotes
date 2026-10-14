#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
int n, k, A, B;
vector<int> position;

ll solve(int left, int right, int beginidx, int endidx)
{
    int cnt = endidx - beginidx;

    if (cnt == 0)
    {
        return A;
    }

    ll lenth = right - left - 1;
    ll burn = B * cnt * lenth;

    if(lenth == 1){
        return burn;
    }
    int mid = (right + left) / 2;

    int splitidx = lower_bound(
                       position.begin() + beginidx,
                       position.begin() + endidx,
                       mid + 1) -
                   position.begin();

    ll divi = solve(left, mid, beginidx, splitidx) + solve(mid + 1, right, splitidx + 1, endidx);

    return min(divi, burn);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> A >> B;
    position.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> position[i];
    }

    cout << solve(1, 1LL << n, 0, k);

    return 0;
}