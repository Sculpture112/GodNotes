#include <bits/stdc++.h>
using namespace std;
int n;
bool ok(int x){
    bool ans = false;
    while(x!=0){
        if(x%10 ==9){
            ans = true;
            break;
        }
        x /= 10;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        int a = 9;
        for (int i = a; i < x;i++){
            if(ok(i) && ok(x-i)){
                cout << i << " " << x - i << "\n";
                break;
            }
        }
    }

    return 0;
}