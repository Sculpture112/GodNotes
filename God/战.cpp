#include <bits/stdc++.h>
using namespace std;
int arr[20005];

int n;
bool find9(){

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            for (int j = i + 1; j < n;j++){
                if(arr[i][j])
            }
        }
    }
}
bool f()
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
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    return 0;
}