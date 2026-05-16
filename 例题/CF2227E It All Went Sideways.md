# []

> **原题链接:** (https://www.luogu.com.cn/problem/CF2227E)

**涉及知识点:** [[单调栈]], [[阶梯]]，[[需重刷]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
解法1:后缀最值 + 频率统计法（极简数学解，最优解）
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // b[i] 存储后缀最小值
    vector<int> b(n);
    b[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        b[i] = min(a[i], b[i + 1]);
    }

    long long sum_a = 0;
    long long sum_b = 0;
    vector<int> freq(n + 1, 0); // a_i 最大为 n，所以频率数组开 n+1 即可
    int max_freq = 0;

    for (int i = 0; i < n; ++i) {
        sum_a += a[i];
        sum_b += b[i];
        freq[b[i]]++;
        max_freq = max(max_freq, freq[b[i]]);
    }

    // 初始状态下移动的方块数
    long long initial_moved = sum_a - sum_b;
    
    // 操作至多一次带来的额外收益：max(0, 最大频率 - 1)
    long long max_gain = max(0, max_freq - 1);

    cout << initial_moved + max_gain << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

解法2:单调栈 + 影响区间计算（经典数据结构视角）
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum_a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }

    // 预处理后缀最小值总和
    vector<int> b(n);
    b[n - 1] = a[n - 1];
    long long sum_b = b[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        b[i] = min(a[i], b[i + 1]);
        sum_b += b[i];
    }
    
    long long initial_moved = sum_a - sum_b;

    // 单调栈寻找左侧第一个严格小于 a[i] 的位置 L[i]
    vector<int> L(n, -1);
    vector<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.back()] >= a[i]) {
            st.pop_back();
        }
        if (!st.empty()) {
            L[i] = st.back();
        }
        st.push_back(i);
    }

    int max_gain = 0;
    int current_suffix_min = a[n - 1];
    
    // 从右向左寻找真正的“影响源头”
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] <= current_suffix_min) {
            current_suffix_min = a[i];
            // a[i] 能向左覆盖到 L[i] 的右边第一个位置，长度为 i - L[i]
            // 减 1 的净收益为 长度 - 1
            int gain = (i - L[i]) - 1;
            max_gain = max(max_gain, gain);
        }
    }

    cout << initial_moved + max_gain << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```

---


