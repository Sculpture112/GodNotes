# include <bits/stdc++.h>

```cpp
# P1706 全排列问题## 题目描述按照字典序输出自然数 $1$ 到 $n$ 所有不重复的排列，即 $n$ 的全排列，要求所产生的任一数字序列中不允许出现重复的数字。## 输入格式一个整数 $n$。## 输出格式由 $1 \sim n$ 组成的所有不重复的数字序列，每行一个序列。每个数字保留 $5$ 个场宽。## 输入输出样例 #1### 输入 #1```3```### 输出 #1```    1    2    3    1    3    2    2    1    3    2    3    1    3    1    2    3    2    1```## 说明/提示$1 \leq n \leq 9$。

include <bits/stdc++.h>
using namespace std;
// #define int long long
// const int N = ;
int n;
int res[10];
bool visited[10];
void solve1(int step)
{  
    if(step>n){
        for(int i =1;i<=n;i++) cout<<setw(5)<<res[i];

        cout<<endl;
        return;
    }

    for(int i =1;i<=n;i++){
        if(!visited[i]){
            visited[i] = true;
            res[step] = i;
            solve1(step + 1);
            visited[i] = false;
        }
    }

}
void solve2(){//在 C++ 中，<algorithm> 头文件提供了一个非常强大的函数 next_permutation。它能直接按字典序生成下一个排列，代码极其简洁。
    vector<int> p(n);
    for(int i = 0;i<n;i++) p[i] = i+1;

    do{
        for(int i = 0;i<n;i++){
            cout<< setw(5) <<p[i];
        }
        cout<<endl;
    }while(next_permutation(p.begin(),p.end()));
    return;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin>>n;
    solve1(1);
    return 0;
}
```
