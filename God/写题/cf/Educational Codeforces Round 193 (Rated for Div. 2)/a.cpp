#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;
#define all(x) (x).begin(), (x).end()

bool isPrime(int x)
{
    if (x % 2 == 0)
        return false;
    for (int i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
bool solve()
{
    int n;
    cin >> n;
    if (n == 2)
        return true;
    return isPrime(n + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
        cout << (solve() ? "YES" : "NO") << "\n";

    return 0;
}