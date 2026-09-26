# [[0]]

> **原题链接:** (https://codeforces.com/problemset/problem/1111/C)

**涉及知识点:** [[分治算法]], [[]]，[[补题]],[[]],[[]]

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

int n, k;
int64 A, B;
vector<int64> position;

/*
    当前需要摧毁的位置区间为 [left, right]。

    position[beginIndex ... endIndex - 1]
    是位于这个区间内的所有复仇者位置。
*/
int64 solve(int64 left, int64 right, int beginIndex, int endIndex) {
    int64 avengers = endIndex - beginIndex;

    // 没有复仇者时，直接摧毁一定最优。
    if (avengers == 0) {
        return A;
    }

    int64 length = right - left + 1;
    int64 burnCost = B * avengers * length;

    // 长度为 1，无法继续分割。
    if (left == right) {
        return burnCost;
    }

    int64 mid = (left + right) / 2;

    // 找到第一个位置大于 mid 的复仇者。
    int splitIndex = lower_bound(
        position.begin() + beginIndex,
        position.begin() + endIndex,
        mid + 1
    ) - position.begin();

    int64 divideCost =
        solve(left, mid, beginIndex, splitIndex) +
        solve(mid + 1, right, splitIndex, endIndex);

    return min(burnCost, divideCost);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k >> A >> B;

    position.resize(k);
    for (int i = 0; i < k; ++i) {
        cin >> position[i];
    }

    sort(position.begin(), position.end());

    // 必须使用 1LL，避免 1 << 30 的整型问题。
    int64 baseLength = 1LL << n;

    cout << solve(1, baseLength, 0, k) << '\n';

    return 0;
}
```

---


