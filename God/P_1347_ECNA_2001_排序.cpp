#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()
bool reach[26][26];
int solve() {
    int n, m;
    cin >> n >> m;

    for (int step = 1; step <= m;step++){
        char a, op, b;
        cin >> a >> op >> b;

        int u = a - 'A';
        int v = b - 'A';

        reach[u][v] = true;

        for (int k = 0; k < 26;k++)
            for (int i = 0; i < 26;i++)
                for (int j = 0; j < 26;j++)
                    reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);

        bool huan = false;
        for (int i = 0; i < n;i++){
            if(reach[i][i]){
                huan = true;
                break;
            }
        }

        if (huan)
        {
            cout << "Inconsistency found after "
                 << step << " relations.\n";
            return 0;
        }

        bool determine = true;
        for (int i = 0; i < n&&determine;i++){

            for (int j = i+1; j < n;j++){
                if(!reach[i][j] && !reach[j][i]){
                    determine = false;
                    break;
                }
            }
        }

        if(determine){
            string ans(n,' ');

            for (int i = 0;i<)
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}