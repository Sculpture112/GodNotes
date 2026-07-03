#include <bits/stdc++.h>
using namespace std;

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        int sum13 = 0;
        for(char c:s){
            if(c == '1' || c== '3'){
                sum13++;
            }
        }
        int sum2 = 0;
        int ans = sum13;
        for(char c:s){
            if(c == '2'){
                sum2++;
            }
            if(c == '1' || c== '3'){
                sum13--;
            }
            ans = max(ans, sum2 + sum13);
        }
        cout << n - ans << "\n";
    }



    return 0;
}