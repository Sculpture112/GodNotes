# [[0]]

> **原题链接:** ()

**涉及知识点:** [[异或]], [[]]，[[补题]],[[]],[[]]

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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int x = 0;
        for (int &v : a) {
            cin >> v;
            x ^= v;
        }

        if (n == 1) {
            cout << 0 << '\n';
            continue;
        }

        if (x == 0) {
            cout << 1 << '\n';
            continue;
        }

        int ans = 0;
        for (int v : a) {
            if ((v ^ x) < v) {
                ++ans;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
```

---


