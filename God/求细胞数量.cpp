#include <bits/stdc++.h>
using namespace std;
int n, m;
int cell = 0;

void dfs(int x,int y)
{

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            if(grid[i][j] != 0){
                cell++;
                grid[i][j] = 0;
                dfs(i, j);
            }
        }
    }

        return 0;
}