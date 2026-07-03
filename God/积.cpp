#include <bits/stdc++.h>
using namespace std;
int t;
long long ans;
void bfs(long long sum,int step,vector<int>& arr)
{
    if(ans!=0){
        return;
    }
    if(sum%9 == 0){
        ans = step;
        return;
    }
    int n = arr.size();
    for (int i = 0; i < n;i++){
        bfs(sum / arr[i] * (arr[i] + 1),step+1,arr);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--)
    {
        ans = 0;
        int n;
        cin >> n;
        vector<int> arr(n);
        long long sum = 1;
        for (int i = 0; i < n; i++)
        {

            cin >> arr[i];
            sum *= arr[i];
        }
        if(sum %9==0){
            cout << 0 << "\n";
            continue;
        }

        

        bfs(sum, 0, arr);
        cout << ans << "\n";
    }

    


    return 0;
}