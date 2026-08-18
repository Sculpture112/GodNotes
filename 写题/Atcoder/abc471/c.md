# []

> **原题链接:** ()

**涉及知识点:** [[贪心算法]], [[双指针]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int64> A(N);
    for (auto &x : A) cin >> x;

    sort(A.begin(), A.end());

    int pos = lower_bound(A.begin(), A.end(), 0LL) - A.begin();

    int l, r;
    int64 cur = 0;
    int64 ans = 0;

    // 第一次从 0 出发
    if (pos == 0) {
        // 全部为正数
        l = r = 0;
        cur = A[0];
    } else if (pos == N) {
        // 全部为负数
        l = r = N - 1;
        cur = A[N - 1];
    } else {
        int left = pos - 1;
        int right = pos;

        if (llabs(A[left]) <= llabs(A[right])) {
            l = r = left;
            cur = A[left];
        } else {
            l = r = right;
            cur = A[right];
        }
    }

    ans += llabs(cur);

    // 继续向左右扩张
    for (int step = 1; step < N; ++step) {
        int64 leftDist = (l > 0 ? llabs(cur - A[l - 1]) : (1LL << 62));
        int64 rightDist = (r + 1 < N ? llabs(A[r + 1] - cur) : (1LL << 62));

        // 相等时选坐标较小的左边点
        if (leftDist <= rightDist) {
            --l;
            cur = A[l];
            ans += leftDist;
        } else {
            ++r;
            cur = A[r];
            ans += rightDist;
        }
    }

    cout << ans << '\n';
    return 0;
}
```

---


