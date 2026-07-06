# []

> **原题链接:** (https://atcoder.jp/contests/abc461/tasks/abc461_d?lang=en)

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, K;
    cin >> H >> W >> K;

    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    // 让平方项尽量小：保证 H <= W
    if (H > W) {
        vector<string> T(W, string(H, '0'));
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                T[j][i] = S[i][j];
            }
        }
        swap(H, W);
        S = T;
    }

    long long ans = 0;

    int maxSum = H * W;
    vector<int> freq(maxSum + 1, 0);

    for (int top = 0; top < H; top++) {
        vector<int> col(W, 0);

        for (int bottom = top; bottom < H; bottom++) {
            for (int j = 0; j < W; j++) {
                col[j] += S[bottom][j] - '0';
            }

            vector<int> touched;
            auto add_freq = [&](int x) {
                if (freq[x] == 0) touched.push_back(x);
                freq[x]++;
            };

            int pref = 0;
            add_freq(0);

            for (int j = 0; j < W; j++) {
                pref += col[j];

                if (pref >= K) {
                    ans += freq[pref - K];
                }

                add_freq(pref);
            }

            for (int x : touched) {
                freq[x] = 0;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
```

---


