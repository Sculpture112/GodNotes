#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 1 << 62;
const double DINF = 1e100;

#define all(x) (x).begin(), (x).end()

void solve() {
    int m, n;
    cin >> m >> n;

    int total = m * n;

    // 给定的操作安排顺序
    vector<int> order(total);
    for (int i = 0; i < total; ++i) {
        cin >> order[i];
    }

    // machineOf[j][k]：工件 j 的第 k 道工序使用的机器
    vector<vector<int>> machineOf(n + 1, vector<int>(m));

    // processTime[j][k]：工件 j 的第 k 道工序加工时间
    vector<vector<int>> processTime(n + 1, vector<int>(m));

    for (int j = 1; j <= n; ++j) {
        for (int k = 0; k < m; ++k) {
            cin >> machineOf[j][k];
        }
    }

    for (int j = 1; j <= n; ++j) {
        for (int k = 0; k < m; ++k) {
            cin >> processTime[j][k];
        }
    }

    vector<vector<pair<int, int>>> schedule(m + 1);

    vector<int> cnt(n+1);

    vector<int> jobEnd(n + 1);

    int ans = 0;

    for(int job : order){
        int k = cnt[job]++;
        int machine = machineOf[job][k];
        int duration = processTime[job][k];

        auto &intervals = schedule[machine];

        int ready = jobEnd[job];
        int start = ready;
        int current = ready;
        int intsertpos = intervals.size();

        for (int i = 0; i < intervals.size(); i++) {
            int left = intervals[i].first;
            int right = intervals[i].second;

            if(current+duration<= left){
                start = current;
                intsertpos = i;
                break;
            }
            current = max(current, right);
        }

        if(intsertpos == intervals.size()){
            start = current;
        }

        int finish = start + duration;

        schedule[machine].insert(intervals.begin() + intsertpos, {start, finish});

        jobEnd[job] = finish;

        ans = max(ans, finish);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) solve();

    return 0;
}