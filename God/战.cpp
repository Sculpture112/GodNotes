#include <bits/stdc++.h>
using namespace std;
int arr[20005];

int n;
bool f()
{
    if()
    for (int i = 0; i < n;i++){
       if(arr[i]!=0 && !f()){
           return true;
           break;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    return 0;
}