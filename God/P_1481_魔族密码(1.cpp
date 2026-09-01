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
    vector<string> chain;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string word;
        cin >> word;
        while (!chain.empty() && word.compare(0, chain.back().size(), chain.back()) != 0)
        {
            chain.pop_back();
        }
        chain.push_back(word);
        ans = max(ans, (int)chain.size());
    }
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