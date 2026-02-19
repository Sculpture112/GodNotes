```cpp

```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){

            cin >> v[i][j];
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<i;j++){
            if(v[i][j]!=0)
            {cout<<"NO";return 0;}
        }
    }
    cout<<"YES";

}
// 64 位输出请用 printf("%lld")
```