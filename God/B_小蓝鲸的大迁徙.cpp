#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> b(N);
    // while (N--)
    // {
    //     int x, y;
    //     cin >> x >> y;
    //     a.push_back(x);
    //     b.push_back(y);
    // }

    for (int i = 0; i < N; i++)
    {
        cin >> a[i] >> b[i];
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << a[i] << " ";
    //     cout << "\n";
    //     cout << b[i] << " ";
    // }

    priority_queue<ll, vector<ll>, greater<ll>> heap;

    if (m - n >= 0)
    {
        cout << 0 << "\n";
        return;
    }
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        if(m>=a[i]){
            heap.push(b[i]);
        }
        else{
            while(!heap.empty() && m < a[i]){
                ans++;
                m += heap.top();
                heap.pop();
            }
            if(m>=a[i]){
                heap.push(b[i]);
            }
            else{
                cout << -1 << "\n";
                return;
            }
        }

    }

    // cout << m;
    // cout << " " << ans;
    if (m >= n)
    {
        cout << ans << "\n";
    }
    else
    {
        while (m < n && !heap.empty())
        {
            m += heap.top();
            ans++;
            heap.pop();
        }
        if (m >= n)
        {
            cout << ans << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
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