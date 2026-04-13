# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[需重刷]],[[]],[[]]

**难度 [[]]


```cpp
// 065 Code01 A*算法模版（对数器验证）

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <climits>

using namespace std;
using namespace std::chrono;

// 0:上，1:右，2:下，3:左
int mv[5] = { -1, 0, 1, 0, -1 };

// 定义状态节点
struct State {
    int x;
    int y;
    int cost; // 距离或预估总代价

    // 重载小于号。C++ 默认大根堆，为了实现小根堆，反转比较逻辑
    bool operator<(const State& other) const {
        return cost > other.cost;
    }
};

// 曼哈顿距离
int f1(int x, int y, int targetX, int targetY) {
    return abs(targetX - x) + abs(targetY - y);
}

// 对角线距离
int f2(int x, int y, int targetX, int targetY) {
    return max(abs(targetX - x), abs(targetY - y));
}

// 欧式距离
double f3(int x, int y, int targetX, int targetY) {
    return sqrt(pow(targetX - x, 2) + pow(targetY - y, 2));
}

// Dijkstra算法
// grid[i][j] == 0 代表障碍
// grid[i][j] == 1 代表道路
// 只能走上、下、左、右，不包括斜线方向
// 返回从(startX, startY)到(targetX, targetY)的最短距离
int minDistance1(const vector<vector<int>>& grid, int startX, int startY, int targetX, int targetY) {
    if (grid[startX][startY] == 0 || grid[targetX][targetY] == 0) {
        return -1;
    }
    int n = grid.size();
    int m = grid[0].size();
    
    // 为了极致性能，这里可以使用一维数组平铺，但为了与 Java 保持结构一致并兼顾可读性，使用二维 vector
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    distance[startX][startY] = 1;
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    priority_queue<State> heap;
    // 放入初始节点
    heap.push({startX, startY, 1});
    
    while (!heap.empty()) {
        State cur = heap.top();
        heap.pop();
        
        int x = cur.x;
        int y = cur.y;
        
        if (visited[x][y]) {
            continue;
        }
        visited[x][y] = true;
        
        if (x == targetX && y == targetY) {
            return distance[x][y];
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + mv[i];
            int ny = y + mv[i + 1];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !visited[nx][ny]) {
                if (distance[x][y] + 1 < distance[nx][ny]) {
                    distance[nx][ny] = distance[x][y] + 1;
                    heap.push({nx, ny, distance[nx][ny]});
                }
            }
        }
    }
    return -1;
}

// A*算法
// grid[i][j] == 0 代表障碍
// grid[i][j] == 1 代表道路
// 只能走上、下、左、右，不包括斜线方向
// 返回从(startX, startY)到(targetX, targetY)的最短距离
int minDistance2(const vector<vector<int>>& grid, int startX, int startY, int targetX, int targetY) {
    if (grid[startX][startY] == 0 || grid[targetX][targetY] == 0) {
        return -1;
    }
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    distance[startX][startY] = 1;
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    priority_queue<State> heap;
    // cost = 走过的距离(1) + 预估距离 f1
    heap.push({startX, startY, 1 + f1(startX, startY, targetX, targetY)});
    
    while (!heap.empty()) {
        State cur = heap.top();
        heap.pop();
        
        int x = cur.x;
        int y = cur.y;
        
        if (visited[x][y]) {
            continue;
        }
        visited[x][y] = true;
        
        if (x == targetX && y == targetY) {
            return distance[x][y];
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + mv[i];
            int ny = y + mv[i + 1];
            
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !visited[nx][ny]) {
                if (distance[x][y] + 1 < distance[nx][ny]) {
                    distance[nx][ny] = distance[x][y] + 1;
                    // 代价 = 起点到相邻点的真实距离 + 相邻点到终点的预估距离
                    heap.push({nx, ny, distance[nx][ny] + f1(nx, ny, targetX, targetY)});
                }
            }
        }
    }
    return -1;
}

// 为了测试
vector<vector<int>> randomGrid(int n) {
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // rand() % 100 产生 0-99 的随机数，模拟概率
            if (rand() % 100 < 30) {
                // 每个格子有30%概率是0
                grid[i][j] = 0;
            } else {
                // 每个格子有70%概率是1
                grid[i][j] = 1;
            }
        }
    }
    return grid;
}

// 为了测试
int main() {
    // 初始化随机数种子
    srand(time(nullptr));

    int len = 100;
    int testTime = 10000;
    cout << "功能测试开始" << "\n";
    for (int i = 0; i < testTime; i++) {
        int n = (rand() % len) + 2;
        vector<vector<int>> grid = randomGrid(n);
        int startX = rand() % n;
        int startY = rand() % n;
        int targetX = rand() % n;
        int targetY = rand() % n;
        
        int ans1 = minDistance1(grid, startX, startY, targetX, targetY);
        int ans2 = minDistance2(grid, startX, startY, targetX, targetY);
        if (ans1 != ans2) {
            cout << "出错了!" << "\n";
            break;
        }
    }
    cout << "功能测试结束" << "\n\n";

    cout << "性能测试开始" << "\n";
    vector<vector<int>> grid = randomGrid(4000);
    int startX = 0;
    int startY = 0;
    int targetX = 3900;
    int targetY = 3900;
    
    // 运行 Dijkstra 测试
    auto start_time = high_resolution_clock::now();
    int ans1 = minDistance1(grid, startX, startY, targetX, targetY);
    auto end_time = high_resolution_clock::now();
    auto duration_ms = duration_cast<milliseconds>(end_time - start_time).count();
    cout << "运行 Dijkstra 算法结果: " << ans1 << ", 运行时间(毫秒) : " << duration_ms << "\n";
    
    // 运行 A* 测试
    start_time = high_resolution_clock::now();
    int ans2 = minDistance2(grid, startX, startY, targetX, targetY);
    end_time = high_resolution_clock::now();
    duration_ms = duration_cast<milliseconds>(end_time - start_time).count();
    cout << "运行 A* 算法结果: " << ans2 << ", 运行时间(毫秒) : " << duration_ms << "\n";
    
    cout << "性能测试结束" << "\n";

    return 0;
}
```

---


**核心套路:** 
**前置母题/相似题目:** [[]]
**时空限制瓶颈:** []

---


## 破题切入点 (思维闪念)
[]
