# P2392 kkksc03考前临时抱佛脚## 题目背景kkksc03 的大学生活非常的颓废，平时根本不学习。但是，临近期末考试，他必须要开始抱佛脚，以求不挂科。## 题目描述这次期末考试，kkksc03 需要考 $4$ 科。因此要开始刷习题集，每科都有一个习题集，分别有 $s_1,s_2,s_3,s_4$ 道题目，完成每道题目需要一些时间，可能不等（$A_1,A_2,\ldots,A_{s_1}$，$B_1,B_2,\ldots,B_{s_2}$，$C_1,C_2,\ldots,C_{s_3}$，$D_1,D_2,\ldots,D_{s_4}$）。kkksc03 有一个能力，他的左右两个大脑可以同时计算 $2$ 道不同的题目，但是仅限于同一科。因此，kkksc03 必须一科一科的复习。由于 kkksc03 还急着去处理洛谷的 bug，因此他希望尽快把事情做完，所以他希望知道能够完成复习的最短时间。## 输入格式本题包含 $5$ 行数据：第 $1$ 行，为四个正整数 $s_1,s_2,s_3,s_4$。第 $2$ 行，为 $A_1,A_2,\ldots,A_{s_1}$ 共 $s_1$ 个数，表示第一科习题集每道题目所消耗的时间。第 $3$ 行，为 $B_1,B_2,\ldots,B_{s_2}$ 共 $s_2$ 个数。第 $4$ 行，为 $C_1,C_2,\ldots,C_{s_3}$ 共 $s_3$ 个数。第 $5$ 行，为 $D_1,D_2,\ldots,D_{s_4}$ 共 $s_4$ 个数，意思均同上。## 输出格式输出一行，为复习完毕最短时间。## 输入输出样例 #1### 输入 #1```1 2 1 3        54 362 4 3```### 输出 #1```20```## 说明/提示$1\leq s_1,s_2,s_3,s_4\leq 20$。$1\leq A_1,A_2,\ldots,A_{s_1},B_1,B_2,\ldots,B_{s_2},C_1,C_2,\ldots,C_{s_3},D_1,D_2,\ldots,D_{s_4}\leq60$。

```

```cpp

# include <bits/stdc++.h>

using namespace std;

int s[5];           // 存储 4 科各自的题目数量
int t[21];          // 存储当前科目的每道题耗时
int total_time;     // 当前科目的总耗时
int total_ans = 0;  // 最终累加的总最短时间
int min_time;       // solve1 用：记录当前科目最小的最大脑负担
int max_left;       // solve2 用：记录单脑在不超过一半时间下的最大负荷

/**
 * 解法一：直观搜索 (Recursive Brute Force)
 * 思路：遍历每道题放在“左脑”还是“右脑”。
 * 当所有题分配完，计算两脑中的最大值，取这些最大值中的最小值。
 */
void dfs1(int step, int current_left, int subject_size) {
    // 边界条件：所有题目都已决定去向
    if (step > subject_size) {
        // total_time - current_left 就是右脑的时间
        // 这一科完成的时间取决于耗时较长的那个大脑
        min_time = min(min_time, max(current_left, total_time - current_left));
        return;
    }

    // 决策 1：把这道题给左脑
    dfs1(step + 1, current_left + t[step], subject_size);

    // 决策 2：把这道题给右脑（左脑时间不变）
    dfs1(step + 1, current_left, subject_size);
}

/**
 * 解法二：折半偏移搜索 (Subset Sum / Knapsack Thinking)
 * 思路：将问题转化为“求左脑能承担的最大时间，且该时间不能超过总时间的一半”。
 * 这样右脑自然承担剩下的部分，且右脑时间必然 >= 左脑。
 */
void dfs2(int step, int current_left, int target, int subject_size) {
    // 剪枝：如果当前左脑时间已经超过了目标（总和的一半），则不需要再试
    if (current_left > target) return;

    if (step > subject_size) {
        // 更新左脑能达到的最大耗时（且 <= target）
        max_left = max(max_left, current_left);
        return;
    }

    // 决策：选或者不选入左脑
    dfs2(step + 1, current_left + t[step], target, subject_size);
    dfs2(step + 1, current_left, target, subject_size);
}

// 对应 solve1 的调用逻辑
void run_solve1() {
    for (int i = 1; i <= 4; i++) cin >> s[i];
    for (int i = 1; i <= 4; i++) {
        total_time = 0;
        min_time = 1e9;
        for (int j = 1; j <= s[i]; j++) {
            cin >> t[j];
            total_time += t[j];
        }
        dfs1(1, 0, s[i]);
        total_ans += min_time;
    }
    cout << total_ans << endl;
}

// 对应 solve2 的调用逻辑
void run_solve2() {
    total_ans = 0;
    for (int i = 1; i <= 4; i++) cin >> s[i];
    for (int i = 1; i <= 4; i++) {
        total_time = 0;
        max_left = 0;
        for (int j = 1; j <= s[i]; j++) {
            cin >> t[j];
            total_time += t[j];
        }
        // 目标是让左脑尽量接近总时长的一半
        int target = total_time / 2;
        dfs2(1, 0, target, s[i]);
        // 完成时间 = 总时间 - 较短的大脑时间
        total_ans += (total_time - max_left);
    }
    cout << total_ans << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    // 两个解法逻辑均正确，solve2 带有简单剪枝，效率略高
    run_solve2(); 
    return 0;
}