# []

> **原题链接:** ()

**涉及知识点:** [[优先队列]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

// state:
// 0 = 仍在充电
// 1 = 已充满
// 2 = 已取出

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    int64 V;
    cin >> Q >> V;

    // 按充满时间排序的小根堆
    priority_queue<
        pair<int64, int>,
        vector<pair<int64, int>>,
        greater<pair<int64, int>>
    > finishHeap;

    // 按 key = w - 插入时间 排序的大根堆
    priority_queue<pair<int64, int>> keyHeap;

    vector<int64> key(Q + 1);
    vector<int> state(Q + 1, 2);

    // 保存已经充满但还没有被取出的电池编号
    vector<int> fullBatteries;

    int batteryId = 0;
    int fullCount = 0;

    for (int qi = 0; qi < Q; ++qi) {
        int type;
        int64 t;
        cin >> type >> t;

        // 把截至当前时间已经充满的电池转移到“已充满”状态
        while (!finishHeap.empty() && finishHeap.top().first <= t) {
            auto [finishTime, id] = finishHeap.top();
            finishHeap.pop();

            // 如果电池已经被取走，则跳过
            if (state[id] != 0) {
                continue;
            }

            state[id] = 1;
            ++fullCount;
            fullBatteries.push_back(id);
        }

        if (type == 1) {
            int64 w;
            cin >> w;

            ++batteryId;

            key[batteryId] = w - t;
            int64 finishTime = t + (V - w);

            state[batteryId] = 0;

            finishHeap.push({finishTime, batteryId});
            keyHeap.push({key[batteryId], batteryId});
        } else {
            // 已充满的电池一定比未充满的电池优先
            if (fullCount > 0) {
                int id = fullBatteries.back();
                fullBatteries.pop_back();

                state[id] = 2;
                --fullCount;

                cout << V << '\n';
            } else {
                // 删除大根堆中的无效电池
                while (!keyHeap.empty() &&
                       state[keyHeap.top().second] != 0) {
                    keyHeap.pop();
                }

                if (keyHeap.empty()) {
                    cout << -1 << '\n';
                } else {
                    auto [k, id] = keyHeap.top();
                    keyHeap.pop();

                    state[id] = 2;

                    // 当前电量 = 当前时间 + (w - 插入时间)
                    cout << t + k << '\n';
                }
            }
        }
    }

    return 0;
}
```

---


