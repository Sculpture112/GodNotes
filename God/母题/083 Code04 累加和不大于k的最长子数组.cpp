#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> minisum(n);
    vector<int> minisumend(n);//这段和是以谁结束
    minisum[n - 1] = arr[n - 1];
    minisumend[n - 1] = n - 1;
    for (int i = n - 2; i >= 0;i--){
        if(minisum[i+1] <0){
            minisum[i] = minisum[i + 1] + arr[i];
            minisumend[i] = minisumend[i + 1];
        }
        else{
            minisum[i] = arr[i];
            minisumend[i] = i;
        }
    }

    int end = 0;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while(end <n && sum + minisum[end] <=k){
            sum += minisum[end];
            end = minisumend[end] + 1;
        }

        if(end>i){
            ans = max(ans, end - i);
            sum -= arr[i];
        }
        else{
            end = i + 1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) cout<<solve();
    
    return 0;
}
