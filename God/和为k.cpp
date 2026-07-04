#include <bits/stdc++.h>
using namespace std;
int h, w, k;
vector<string> grid;
void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> h >> w >> k;
    grid.resize(h);
    for (int i = 0; i < h;i++){
        cin >> grid[i];
    }

    vector<vector<int>> arr(h + 1, vector<int>(w + 1, 0));
    for (int i = 1; i <= h;i++){
        for (int j = 1; j <= w;j++){
            arr[i][j] = grid[i - 1][j - 1]-'0';
        }
    }

    for (int i = 1; i <= h;i++){
        for (int j = 1; i <= w;j++){
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }

    long long ans = 0;
    for (int i = 1; i <= h;i++){
        for (int j = 1; j <= w;j++){

            for (int x = i; x >= 1;x--){
                for (int y = j; y >= 1;y--){

                    if(arr[i][j] -arr[i][y-1] -arr[x-1][j] + arr[x-1][y-1] == k){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans;

    return 0;
}