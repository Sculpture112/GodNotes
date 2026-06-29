#include <bits/stdc++.h>
using namespace std;
int arr[200005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int query[q + 1][3];
    for (int i = 1; i <= q; i++)
    {
        int temp;
        cin >> temp;
        query[i][0] = temp;
        if (temp == 1)
        {
            cin >> query[i][1];
        }
        else
        {
            cin >> query[i][1] >> query[i][2];
        }
    }

    for (int i = 1; i <= q; i++)
    {
        if (query[i][0] == 1)
        {
            int t = query[i][1];
            // cout << arr[t] << " " << arr[t + 1] << "\n";
            int temp = arr[t];
            arr[t] = arr[t + 1];
            arr[t + 1] = temp;
            // cout << arr[t] << " " << arr[t + 1] <<"\n";
        }
        else
        {
            int l = query[i][1], r = query[i][2];
            // cout << l << " " << r << "\n";
            int sum = 0;
            for (int i = l; i <= r;i++){
                sum += arr[i];
            }
            cout << sum << "\n";
        }
    }

    return 0;
}