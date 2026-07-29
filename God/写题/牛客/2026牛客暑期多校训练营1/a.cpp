#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s.size() != 8)
        {
            cout << "Well-Being" << "\n";
            continue;
        }

        bool p = true;
        for (int i = 0; i < 8; i++)
        {
            if (p == false)
                continue;
            if ((i + 1) % 2 == 0)
            {
                if ((s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u'))
                    p = false;
            }
            else if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                p = false;
            }
        }
        cout <<(p ? "Suspected Virus" : "Well-Being");
        cout << "\n";
    }
    return 0;
}