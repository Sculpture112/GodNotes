# [[0]]

> **原题链接:** (https://codeforces.com/gym/715305/problem/D)

**涉及知识点:** [[状态机dp]], [[快速幂]]，[[补题]],[[矩阵快速幂]],[[]]

**核心套路:** 

[[2026-09-14-21-05-01]]
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

// M[i][j] 表示 i 状态到 j 状态可不可以实现

// 矩阵 × 矩阵
Matrix operator*(const Matrix& x, const Matrix& y) {
    Matrix z;

    // z[i][j] = x 的第 i 行 × y 的第 j 列
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            for (int k = 0; k < K; ++k) {
                z.a[i][j] =
                    (z.a[i][j] + x.a[i][k] * y.a[k][j]) % MOD; // 第i行乘以第j列
            }
        }
    }

    return z;
}

// 行向量 × 矩阵
array<int64, K> operator*(const array<int64, K>& x,
                          const Matrix& y) {
    array<int64, K> z{};

    // z[j] = 行向量 x × 矩阵 y 的第 j 列
    for (int j = 0; j < K; ++j) {
        for (int k = 0; k < K; ++k) {
            z[j] = (z[j] + x[k] * y.a[k][j]) % MOD; // 固定j列, 第k个方案数乘以第k个能否到底j 等于这个方案增加的数量 [[2026-09-17-09-45-54]]
        } // 意为x[k] * a[k][j] ,第k个状态能不能到达j状态
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
	// 新状态都可以由旧状态转移,所以直接计算矩阵快速幂,加速转移
    Matrix trans;
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            trans.a[i][j] = raw[i][j];
        }
    }

    // M[i][j] 表示 i 状态到 j 状态可不可以实现

    // 所有测试用例共用这些矩阵幂
    array<Matrix, LOG> pw;
    pw[0] = trans;

    for (int i = 1; i < LOG; ++i) {
        pw[i] = pw[i - 1] * pw[i - 1];
    }

    // 计算矩阵快速幂

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


