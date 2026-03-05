# typedef long long ll; 必须用 long

> 

> 

>

```cpp
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll; // 必须用 long long 避坑

const int MAXN = 1e5 + 5;
ll tree[MAXN << 2], lazy[MAXN << 2], a[MAXN];

// 向上更新父节点
void push_up(int rt) {
    tree[rt] = tree[rt << 1] + tree[rt << 1 | 1];
}

// 向下传递懒标记
void push_down(int rt, int l, int r) {
    if (lazy[rt]) {
        int mid = (l + r) >> 1;
        // 左子树更新
        lazy[rt << 1] += lazy[rt];
        tree[rt << 1] += lazy[rt] * (mid - l + 1);
        // 右子树更新
        lazy[rt << 1 | 1] += lazy[rt];
        tree[rt << 1 | 1] += lazy[rt] * (r - mid);
        // 清空当前标记
        lazy[rt] = 0;
    }
}

// 建树
void build(int rt, int l, int r) {
    if (l == r) {
        tree[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
}

// 区间修改 [L, R] 加上 k
void update(int rt, int l, int r, int L, int R, ll k) {
    if (L <= l && r <= R) {
        tree[rt] += k * (r - l + 1);
        lazy[rt] += k;
        return;
    }
    push_down(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(rt << 1, l, mid, L, R, k);
    if (R > mid) update(rt << 1 | 1, mid + 1, r, L, R, k);
    push_up(rt);
}

// 区间查询 [L, R]
ll query(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) return tree[rt];
    push_down(rt, l, r);
    int mid = (l + r) >> 1;
    ll res = 0;
    if (L <= mid) res += query(rt << 1, l, mid, L, R);
    if (R > mid) res += query(rt << 1 | 1, mid + 1, r, L, R);
    return res;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

    build(1, 1, n);

    while (m--) {
        int opt, x, y;
        ll k;
        scanf("%d", &opt);
        if (opt == 1) {
            scanf("%d %d %lld", &x, &y, &k);
            update(1, 1, n, x, y, k);
        } else {
            scanf("%d %d", &x, &y);
            printf("%lld\n", query(1, 1, n, x, y));
        }
    }
    return 0;
}
```
