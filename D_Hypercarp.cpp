#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    ll x, y;
    cin >> x >> y;

    ll bestDist = LINF;
    int bestN = 0;
    ll bestP = 0;

    for (int n = 1;; n++) {
        ll sum = 1LL * n * (n + 1) / 2;
        if (sum > x + y) break;

        ll left = max(0LL, sum - y);
        ll right = min(sum, x);

        // For fixed sum, the unconstrained optimum is
        // p = (sum + x - y) / 2. Check both neighboring integers.
        ll center = sum + x - y;
        ll p1 = center / 2;
        ll p2 = p1 + 1;

        for (ll p : {p1, p2}) {
            p = clamp(p, left, right);
            ll q = sum - p;
            ll dist = (x - p) * (x - p) + (y - q) * (y - q);

            if (dist < bestDist) {
                bestDist = dist;
                bestN = n;
                bestP = p;
            }
        }
    }

    string ans(bestN, 'Y');
    ll need = bestP;

    // The operation at position i contributes bestN-i to the x-coordinate.
    // Greedily select a subset of 1..bestN whose sum is bestP.
    for (int weight = bestN; weight >= 1; weight--) {
        if (need >= weight) {
            need -= weight;
            int pos = bestN - weight;
            ans[pos] = 'X';
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
