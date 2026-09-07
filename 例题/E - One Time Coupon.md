# []

> **原题链接:** (https://atcoder.jp/contests/abc474/tasks/abc474_e)

**涉及知识点:** [[贪心算法]], [[0]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]

**触发条件：**

**关键观察/不变量：**

**最容易错的边界：**

**我第一次卡在哪里：**

**下次看到什么信号要想到它：**

**一个相似变式：**

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long sumA = 0;
        long long minA = (long long)4e18;
        vector<long long> save(N);

        for (int i = 0; i < N; ++i) {
            long long A, B;
            cin >> A >> B;

            sumA += A;
            minA = min(minA, A);
            save[i] = A - B;
        }

        sort(save.rbegin(), save.rend());

        long long answer = sumA;
        long long prefixSave = 0;

        for (int c = 1; c <= N; ++c) {
            prefixSave += save[c - 1];

            long long extraCoupons = max(0LL, 2LL * c - N);
            long long cost =
                sumA - prefixSave + extraCoupons * minA;

            answer = min(answer, cost);
        }

        cout << answer << '\n';
    }

    return 0;
}
```

---


