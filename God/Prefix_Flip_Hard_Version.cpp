#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string a, b;
        cin >> n >> a >> b;
        vector<int> ans;
        bool rev = false;
        auto get = [&](int pos)
        {
            char x = a[pos];
            if (rev)
            {
                x = (x == '0' ? '1' : '0');
            }
            return x;
        };
        int l = 0, r = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            char first = rev ? get(r) : get(l);
            char last = rev ? get(l) : get(r);

            if (last == b[i])
            {
                if (rev)
                {
                    l++;
                }
                else
                {
                    r--;
                }
                continue;
            }

            if (first == b[i])
            {
                b[i] = !b[i];
                ans.push_back(1);
            }
            ans.push_back(i + 1);
            rev = !rev;
            if (rev)
                l++;
            else
                r--;
        }
        cout << ans.size();
        for (int i = 0; i < ans.size();i++){
            cout << " " << ans[i];
        }
        cout << "\n";
    }

    return 0;
}