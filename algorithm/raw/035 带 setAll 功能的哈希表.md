// 035 带 setAll 功能的哈希表

# include <cstdio>

# include <unordered_map>

using namespace std;

// 存储结构：first为值，second为时间戳
unordered_map<int, pair<int, int>> dataMap;
int setAllValue, setAllTime = -1, cnt = 0; // 全局setAll值、全局时间、当前时间计数

void put(int k, int v) { dataMap[k] = {v, cnt++}; } // 正常放入，赋予当前时间戳

void setAll(int v) { setAllValue = v; setAllTime = cnt++; } // 更新全局值，更新全局时间

int get(int k) {
    if (dataMap.find(k) == dataMap.end()) return -1; // 不存在返回-1
    auto& p = dataMap[k];
    // 如果记录的时间戳早于 setAll 时间，说明该值已被覆盖
    return p.second > setAllTime ? p.first : setAllValue;
}

int main() {
    int n, op, a, b;
    while (scanf("%d", &n) != EOF) {
        dataMap.clear(); setAllTime = -1; cnt = 0; // 每一组测试数据前重置
        for (int i = 0; i < n; i++) {
            scanf("%d", &op);
            if (op == 1) { scanf("%d %d", &a, &b); put(a, b); }
            else if (op == 2) { scanf("%d", &a); printf("%d\n", get(a)); }
            else { scanf("%d", &a); setAll(a); }
        }
    }
    return 0;
}