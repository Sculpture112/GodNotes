# []

> **原题链接:** ()

**涉及知识点:** [[贪心算法]], [[前缀和]]，[[补题]],[[枚举分割点]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    // 排序不改变数组总和，却能让我们按大小选择中位数及其两侧元素。
    sort(a.begin(), a.end());

    // pre[i] = a[0] + ... + a[i - 1]。
    // 因此区间 [l, r) 的元素和为 pre[r] - pre[l]。
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    ll base = pre[n];          // 操作前整个数组的总和
    ll best = LLONG_MIN;       // 一次操作能够带来的最大变化量

    if (k & 1) {
        // k = 2m + 1，中位数是唯一的中间元素。
        int m = k / 2;

        // 固定 a[idx] 为中位数。
        // idx >= m：保证它前面至少能选 m 个数。
        // idx + m < n：保证它后面至少能选 m 个数。
        for (int idx = m; idx + m < n; idx++) {
            // 为使原来选中元素的和最小：
            // 左侧选全局最小的 m 个 a[0...m-1]；
            // 右侧选 a[idx] 后最小的 m 个 a[idx+1...idx+m]。
            // a[idx] 操作前后都等于中位数，对变化量没有贡献，故不计入 old。
            ll old = pre[m] + (pre[idx + m + 1] - pre[idx + 1]);

            // 上面这 2m = k-1 个数操作后全都变成 a[idx]。
            ll nw = 1LL * (k - 1) * a[idx];

            best = max(best, nw - old);
        }
    } else {
        // k = 2m，中位数是中间两个数的平均值。
        int m = k / 2;

        // 固定 a[j] 为右中位数。最优的左中位数一定是紧邻的 a[j-1]。
        // j >= m：前面有足够的元素；j + m <= n：右边有足够的元素。
        for (int j = m; j + m <= n; j++) {
            // 选中的 k 个元素为：
            // a[0...m-2]、a[j-1]、a[j...j+m-1]。
            ll old = pre[m - 1] + a[j - 1]
                     + (pre[j + m] - pre[j]);

            // 中位数为 (a[j-1] + a[j]) / 2。
            // 2m 个数操作后的总和为 m * (a[j-1] + a[j])，保证是整数。
            ll nw = 1LL * m * (a[j - 1] + a[j]);

            best = max(best, nw - old);
        }
    }

    cout << base + best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();
}


```

---


