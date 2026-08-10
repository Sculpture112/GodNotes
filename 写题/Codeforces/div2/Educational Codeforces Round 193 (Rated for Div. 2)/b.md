# []

> **原题链接:** ()

**涉及知识点:** [[分类讨论]], [[连续段压缩]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]


Q
```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    // color[i] 表示第 i 个连续段的颜色
    // cnt[i] 表示第 i 个连续段的长度
    vector<int> color, cnt;

    // 将连续相同的元素压缩成一个段
    for (int x : a) {
        if (!color.empty() && color.back() == x) {
            cnt.back()++;
        } else {
            color.push_back(x);
            cnt.push_back(1);
        }
    }

	int m = color.size();

    // 不进行交换时，每个连续段保留一个元素
    // 相邻连续段颜色不同，所以基础答案为段数 m
    int ans = m;

    // 枚举相邻的两个连续段
    for (int i = 0; i + 1 < m; i++) {
        // 两段长度都至少为 2：
        // X X Y Y -> X Y X Y
        // 两段可以各多保留一个元素，答案增加 2
        if (cnt[i] >= 2 && cnt[i + 1] >= 2) {
            ans = max(ans, m + 2);
        }

        // 左段长度至少为 2：
        // X X Y -> X Y X
        // 交换后以 X 结尾，因此右边下一段不能也是 X
        if (cnt[i] >= 2 &&
            (i + 2 >= m || color[i + 2] != color[i])) {
            ans = max(ans, m + 1);
        }

        // 右段长度至少为 2：
        // X Y Y -> Y X Y
        // 交换后以 Y 开头，因此左边上一段不能也是 Y
        if (cnt[i + 1] >= 2 &&
            (i == 0 || color[i - 1] != color[i + 1])) {
            ans = max(ans, m + 1);
        }
    }

    // 枚举中间隔着一个连续段的情况
    for (int i = 0; i + 2 < m; i++) {
        // 结构为 X X | Z | Y Y
        // 删除中间的 Z 段后得到 X X Y Y
        // 交换中间两个元素后变成 X Y X Y
        //
        // 两端一共多保留 2 个元素，中间少保留 1 个元素，
        // 所以净收益为 1
        //
        // X 和 Y 必须不同，否则交换没有作用
        if (cnt[i] >= 2 &&
            cnt[i + 2] >= 2 &&
            color[i] != color[i + 2]) {
            ans = max(ans, m + 1);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TestsNumT = 1;
    cin >> TestsNumT;

    while (TestsNumT--) {
        solve();
    }

    return 0;
}
```

---


