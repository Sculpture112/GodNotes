#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++)
        cin >> a[i];

    ll ans = 1;
    vector<int> b(n);
    for(int x : a){
        if(ans<x){
            break;
        }
        ans += x;
        b.push_back(ans);
    }

    if(b.size() != a.size()){
        while(b.size() == a.size()){
            b.push_back(ans);
        }
    }
    cout << b[0];
    for (int i = 1; i < n;i++){
        cout <<" "<< b[i];
    }

        return 0;
}