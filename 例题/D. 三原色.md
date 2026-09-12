# [[0]]

> **原题链接:** (https://codeforces.com/gym/715305/problem/D)

**涉及知识点:** [[状态机dp]], [[快速幂]]，[[补题]],[[]],[[]]

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

using int64 = long long;

constexpr int K = 6;
constexpr int LOG = 41;  // 2^40 > 10^12
constexpr int64 MOD = 998244353;

struct Matrix {
    int64 a[K][K]{};
};

Matrix operator*(const Matrix& x, const Matrix& y) {
    Matrix z;

    for (int i = 0; i < K; ++i) {
        for (int k = 0; k < K; ++k) {
            if (x.a[i][k] == 0) continue;

            for (int j = 0; j < K; ++j) {
                z.a[i][j] =
                    (z.a[i][j] + x.a[i][k] * y.a[k][j]) % MOD;
            }
        }
    }

    return z;
}

array<int64, K> operator*(const array<int64, K>& x,
                          const Matrix& y) {
    array<int64, K> z{};

    for (int k = 0; k < K; ++k) {
        if (x[k] == 0) continue;

        for (int j = 0; j < K; ++j) {
            z[j] = (z[j] + x[k] * y.a[k][j]) % MOD;
        }
    }

    return z;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /*
       状态编号：
       0: 没有 R，结尾 0 个 B
       1: 没有 R，结尾 1 个 B
       2: 没有 R，结尾 2 个 B
       3: 已有 1 个 R，结尾 0 个 B
       4: 已有 1 个 R，结尾 1 个 B
       5: 已有 1 个 R，结尾 2 个 B
    */

    const int raw[K][K] = {
        {1, 1, 0, 1, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 1, 0, 0}
    };

    Matrix trans;
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            trans.a[i][j] = raw[i][j];
        }
    }

    // 所有测试用例共用这些矩阵幂
    array<Matrix, LOG> pw;
    pw[0] = trans;

    for (int i = 1; i < LOG; ++i) {
        pw[i] = pw[i - 1] * pw[i - 1];
    }

    int T;
    cin >> T;

    while (T--) {
        int64 n;
        cin >> n;

        // 长度为 1 时分别为 G、B、R
        array<int64, K> dp = {1, 1, 0, 1, 0, 0};

        int64 exponent = n - 1;

        for (int bit = 0; exponent > 0; ++bit, exponent >>= 1) {
            if (exponent & 1LL) {
                dp = dp * pw[bit];
            }
        }

        int64 answer = 0;
        for (int i = 0; i < K; ++i) {
            answer = (answer + dp[i]) % MOD;
        }

        cout << answer << '\n';
    }

    return 0;
}
```

---


