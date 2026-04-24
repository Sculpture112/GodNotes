# []

> **原题链接:** (https://www.nowcoder.com/practice/aaefe5896cce4204b276e213e725f3ea)

**涉及知识点:** [[]], [[]]，[[需重刷]],[[]],[[]]

**核心套路:** 


```cpp
// 067 Code05 节点数为n高度不大于m的二叉树个数

// 现在有n个节点，计算出有多少个不同结构的二叉树
// 满足节点个数为n且树的高度不超过m的方案
// 因为答案很大，所以答案需要模上1000000007后输出
// 测试链接 : https://www.nowcoder.com/practice/aaefe5896cce4204b276e213e725f3ea
// C++ 提交时直接全部复制提交即可通过

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 55;
const int MOD = 1000000007;

// 记忆化搜索使用的数组
long long dp1[MAXN][MAXN];
// 二维动态规划使用的数组
long long dp2[MAXN][MAXN];
// 空间压缩一维动态规划使用的数组
long long dp3[MAXN];

// 二叉树节点数为 n
// 高度不能超过 m
// 结构数返回
// 记忆化搜索
int compute1(int n, int m) {
    if (n == 0) {
        return 1;
    }
    // n > 0
    if (m == 0) {
        return 0;
    }
    if (dp1[n][m] != -1) {
        return (int)dp1[n][m];
    }
    long long ans = 0;
    // n 个点，头占掉 1 个
    for (int k = 0; k < n; k++) {
        // 一共 n 个节点，头节点已经占用了 1 个名额
        // 如果左树占用 k 个，那么右树就占用 i - k - 1 个
        ans = (ans + (1LL * compute1(k, m - 1) * compute1(n - k - 1, m - 1)) % MOD) % MOD;
    }
    dp1[n][m] = ans;
    return (int)ans;
}

// 严格位置依赖的动态规划
int compute2(int n, int m) {
    // 每次计算前初始化数组
    memset(dp2, 0, sizeof(dp2));
    for (int j = 0; j <= m; j++) {
        dp2[0][j] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp2[i][j] = 0;
            for (int k = 0; k < i; k++) {
                // 一共 i 个节点，头节点已经占用了 1 个名额
                // 如果左树占用 k 个，那么右树就占用 i - k - 1 个
                dp2[i][j] = (dp2[i][j] + dp2[k][j - 1] * dp2[i - k - 1][j - 1] % MOD) % MOD;
            }
        }
    }
    return (int)dp2[n][m];
}

// 空间压缩
int compute3(int n, int m) {
    // 每次计算前初始化数组
    memset(dp3, 0, sizeof(dp3));
    dp3[0] = 1;
    for (int i = 1; i <= n; i++) {
        dp3[i] = 0;
    }
    for (int j = 1; j <= m; j++) {
        // 根据依赖，一定要先枚举列
        for (int i = n; i >= 1; i--) {
            // 再枚举行，而且 i 不需要到达 0，i >= 1 即可
            dp3[i] = 0;
            for (int k = 0; k < i; k++) {
                // 枚举
                dp3[i] = (dp3[i] + dp3[k] * dp3[i - k - 1] % MOD) % MOD;
            }
        }
    }
    return (int)dp3[n];
}

int main() {
    // C++ 的快速 I/O 模板，极大提升读写效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 为记忆化搜索初始化 dp1
    memset(dp1, -1, sizeof(dp1));

    int n, m;
    // 等同于 Java 的 in.nextToken() != StreamTokenizer.TT_EOF
    while (cin >> n >> m) {
        // 三种方法任选其一均可
        // cout << compute1(n, m) << "\n";
        // cout << compute2(n, m) << "\n";
        cout << compute3(n, m) << "\n";
    }

    return 0;
}
```

---



**前置母题/相似题目:** [[]]
**时空限制瓶颈:** []

---


## 破题切入点 (思维闪念)
[]
