# []

> **原题链接:** (https://atcoder.jp/contests/abc474/tasks/abc474_d)

**涉及知识点:** [[构造]], [[]]，[[补题]],[[]],[[]]

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

    int N;
    cin >> N;

    vector<long long> A(N), B(N);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    int pos = -1;
    for (int i = 0; i < N; ++i) {
        if (A[i] > B[i]) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "No\n";
        return 0;
    }

    vector<long long> W(N, 1);
    W[pos] = 1000000000000000000LL; // 10^18

    cout << "Yes\n";
    for (int i = 0; i < N; ++i) {
        if (i) cout << ' ';
        cout << W[i];
    }
    cout << '\n';

    return 0;
}
```

---


