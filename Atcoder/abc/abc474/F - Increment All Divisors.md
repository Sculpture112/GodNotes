# []

> **原题链接:** ()

**涉及知识点:** [[莫比乌斯反演]], [[莫比乌思]]，[[补题]],[[欧拉筛]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]

**触发条件：**

$$
C_j= \sum_{t=1}^{\lfloor N/j\rfloor} \mu(t)(X-A_{jt})
$$
$$
C_j= X\sum_t\mu(t) - \sum_t\mu(t)A_{jt}
$$
**关键观察/不变量：**

**最容易错的边界：**

**我第一次卡在哪里：**

**下次看到什么信号要想到它：**

**一个相似变式：**

莫比乌斯反演
```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int64> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // 线性筛求莫比乌斯函数
    vector<int> mu(N + 1);
    vector<int> primes;
    vector<bool> composite(N + 1, false);

    mu[1] = 1;

    for (int i = 2; i <= N; ++i) {
        if (!composite[i]) {
            primes.push_back(i);
            mu[i] = -1;
        }

        for (int p : primes) {
            if (1LL * i * p > N) {
                break;
            }

            composite[i * p] = true;

            if (i % p == 0) {
                mu[i * p] = 0;
                break;
            }

            mu[i * p] = -mu[i];
        }
    }

    // X 至少不能小于原数组最大值
    int64 lower = *max_element(A.begin() + 1, A.end());

    const int64 INF = 4'000'000'000'000'000'000LL;
    int64 upper = INF;

    for (int j = 1; j <= N; ++j) {
        // C_j = coef * X + constant
        int64 coef = 0;
        int64 constant = 0;

        for (int t = 1; j * t <= N; ++t) {
            coef += mu[t];
            constant -= 1LL * mu[t] * A[j * t];
        }

        // 要求 coef * X + constant >= 0
        if (coef > 0) {
            if (constant < 0) {
                int64 need =
                    (-constant + coef - 1) / coef;

                lower = max(lower, need);
            }
        } else if (coef == 0) {
            if (constant < 0) {
                cout << -1 << '\n';
                return 0;
            }
        } else {
            if (constant < 0) {
                cout << -1 << '\n';
                return 0;
            }

            upper = min(
                upper,
                constant / (-coef)
            );
        }
    }

    if (lower > upper) {
        cout << -1 << '\n';
    } else {
        cout << lower - A[1] << '\n';
    }

    return 0;
}
```




```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int64> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    // C[i] = coef[i] * x + constant[i]
    vector<int64> coef(N + 1);
    vector<int64> constant(N + 1);

    int64 lower = *max_element(A.begin() + 1, A.end());
    int64 upper = 4'000'000'000'000'000'000LL;

    for (int i = N; i >= 1; --i) {
        // C[i] = x - A[i] - C[2i] - C[3i] - ...
        coef[i] = 1;
        constant[i] = -A[i];

        for (int j = i + i; j <= N; j += i) {
            coef[i] -= coef[j];
            constant[i] -= constant[j];
        }

        // coef[i] * x + constant[i] >= 0
        if (coef[i] > 0) {
            if (constant[i] < 0) {
                int64 need =
                    (-constant[i] + coef[i] - 1) / coef[i];
                lower = max(lower, need);
            }
        } else if (coef[i] == 0) {
            if (constant[i] < 0) {
                cout << -1 << '\n';
                return 0;
            }
        } else {
            // coef[i] < 0:
            // x <= constant[i] / (-coef[i])
            if (constant[i] < 0) {
                cout << -1 << '\n';
                return 0;
            }

            upper = min(
                upper,
                constant[i] / (-coef[i])
            );
        }
    }

    if (lower > upper) {
        cout << -1 << '\n';
    } else {
        cout << lower - A[1] << '\n';
    }

    return 0;
}
```

---


