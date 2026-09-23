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
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    string s;
    cin >> s;

    int totalzero = count(a.begin(), a.end(), 0);
    int seenone = 0;
    int seenzero = 0;
    vector<int> zeroafterone;
    // zeroAfterOne[i]:
    // 按照从左到右的顺序，第 i 个 1 的右边有多少个 0
    vector<int> onebeforezero;
    // oneBeforeZero:
    // 最后会反转，使其按照 0 从右到左的顺序排列
    ll inversion = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            seenone++;
            zeroafterone.push_back(totalzero - seenzero);
        }
        else
        {
            seenzero++;
            inversion += seenone;
            onebeforezero.push_back(seenone);
        }
    }
    reverse(onebeforezero.begin(), onebeforezero.end());

    cout << inversion << " ";

    int usedone = 0, usedzero = 0;
    for (char c : s)
    {
        if (c == '1')
        {
            if (usedone < zeroafterone.size())
            {
                int removed = max(0, zeroafterone[usedone] - usedzero);
                inversion -= removed;
                usedone++;
            }
        }
        else
        {
            if(usedzero<onebeforezero.size()){
                int removed = max(0, onebeforezero[usedzero] - usedone);
                inversion -= removed;
                usedzero++;
            }
        }
        cout << inversion << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
        solve();

    return 0;
}