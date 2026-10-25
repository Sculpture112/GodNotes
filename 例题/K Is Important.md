# [[0]]

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

- 题目中的什么条件提示了这个方向？
- 从最直接的做法出发，怎样走到关键观察？
- 如果没见过这题，我能靠什么发现它？


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
        int n, k;
        cin >> n >> k;

        long long ans = 0;
        vector<int> vec;
        vec.reserve(n);

        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;

            // 必删的中间部分直接计入答案
            if (k <= i && i <= n - k + 1) {
                ans += x;
            } else {
                vec.push_back(x);
            }
        }

        // 最终留下 k - 1 个元素，计算还需要删除多少个
        int take = max(0, static_cast<int>(vec.size()) - (k - 1));

        int l = 0;
        int r = static_cast<int>(vec.size()) - 1;

        // 这里只计算各对贡献，无需模拟实际删除顺序
        while (take--) {
            ans += max(vec[l], vec[r]);
            ++l;
            --r;
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---


