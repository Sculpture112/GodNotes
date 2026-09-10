# [[1]]

> **原题链接:** (https://codeforces.com/contest/2259/problem/F)

**涉及知识点:** [[构造]], [[贡献法]]，[[补题]],[[逆序对]],[[]]

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) {
            cin >> x;
        }

        string s;
        cin >> s;

        int totalZero = count(a.begin(), a.end(), 0);

        // zeroAfterOne[i]:
        // 按照从左到右的顺序，第 i 个 1 的右边有多少个 0
        vector<int> zeroAfterOne;

        // oneBeforeZero:
        // 最后会反转，使其按照 0 从右到左的顺序排列
        vector<int> oneBeforeZero;

        int seenZero = 0;
        int seenOne = 0;
        int64 inversions = 0;

        for (int x : a) {
            if (x == 1) {
                zeroAfterOne.push_back(totalZero - seenZero);
                ++seenOne;
            } else {
                // 当前 0 与左边每个 1 都组成逆序对
                inversions += seenOne;
                oneBeforeZero.push_back(seenOne);
                ++seenZero;
            }
        }

        // reverse bubble 每次处理最右边尚未处理的 0
        reverse(oneBeforeZero.begin(), oneBeforeZero.end());

        int usedOne = 0;
        int usedZero = 0;

        cout << inversions;

        for (char operation : s) {
            if (operation == '1') {
                // 正向 bubble：处理最左边尚未处理的 1
                if (usedOne < static_cast<int>(zeroAfterOne.size())) {
                    int removed = max(
                        0,
                        zeroAfterOne[usedOne] - usedZero
                    );

                    inversions -= removed;
                    ++usedOne;
                }
            } else {
                // 反向 bubble：处理最右边尚未处理的 0
                if (usedZero < static_cast<int>(oneBeforeZero.size())) {
                    int removed = max(
                        0,
                        oneBeforeZero[usedZero] - usedOne
                    );

                    inversions -= removed;
                    ++usedZero;
                }
            }

            cout << ' ' << inversions;
        }

        cout << '\n';
    }

    return 0;
}
```

---


