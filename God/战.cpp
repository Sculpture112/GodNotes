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
        int n;
        cin >> n;
        vector<int> arr(n + 1);
        for (int i = 0; i < n;i++){
            cin >> arr[i];
        }

        int cnt = 0;

        vector<int> st;
        for (int i = 0; i < n;i++){
            int x = arr[i]%9;
            
            if(!st.empty() && (x + st.back())%9 == 0)
            {
                cnt++;
                st.pop_back();
            }
            else{
                st.push_back(x);
            }
        }
    }
    solve();

    return 0;
}