# []

> **原题链接:** (https://atcoder.jp/contests/abc474/tasks/abc474_c)

**涉及知识点:** [[最后一次出现的位置]], [[0]]，[[补题]],[[链表]],[[]]

**核心套路:** 
[两种方法]
链表直观易懂
## 破题切入点 (思维闪念)
[]

**触发条件：**

**关键观察/不变量：**

**最容易错的边界：**

**我第一次卡在哪里：**

**下次看到什么信号要想到它：**

**一个相似变式：**

链表
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    list<int> seq;
    vector<list<int>::iterator> pos(N + 1);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        seq.push_back(x);
        pos[x] = prev(seq.end());
    }

    while (Q--) {
        int x;
        cin >> x;

        seq.erase(pos[x]);

        seq.push_back(x);
        pos[x] = prev(seq.end());
    }

    bool first = true;
    for (int x : seq) {
        if (!first) cout << ' ';
        cout << x;
        first = false;
    }
    cout << '\n';

    return 0;
}
```

	last数组
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


