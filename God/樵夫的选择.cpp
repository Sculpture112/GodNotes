#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int arr1[n+1];
    int arr2[n+1];
    bool ans = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> arr2[i];
        if(arr1[arr2[i]]!=i){
            ans = false;
        }    
    }
    if(ans){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}