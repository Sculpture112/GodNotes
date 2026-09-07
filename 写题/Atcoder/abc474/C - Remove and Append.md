# []

> **原题链接:** (https://atcoder.jp/contests/abc474/tasks/abc474_c)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

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

    int N, Q;
    cin >> N >> Q;

    vector<int> P(N);
    for (int &x : P) cin >> x;

    vector<int> a(Q + 1);
    vector<int> last(N + 1, 0);

    for (int i = 1; i <= Q; i++) {
        cin >> a[i];
        last[a[i]] = i;
    }

    vector<int> ans;

    // 没有被操作过的元素，保留原来的相对顺序
    for (int x : P) {
        if (last[x] == 0) {
            ans.push_back(x);
        }
    }

    // 被操作过的元素，按照最后一次操作的先后顺序排列
    for (int i = 1; i <= Q; i++) {
        if (last[a[i]] == i) {
            ans.push_back(a[i]);
        }
    }

    for (int i = 0; i < N; i++) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}
```

---


