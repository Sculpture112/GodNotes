#include <bits/stdc++.h>
using namespace std;
int arr[20005];

int n;
bool find9()
{

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] + arr[j] ==9)
                {
                    arr[i] = -1;
                    arr[j] = -1;
                    return true;
                }
            }
        }
    }
    return false;
}
bool f()
{

    if(find9() && !f()){
        return true;
    }
    return false;
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
    cout<<f();

    return 0;
}