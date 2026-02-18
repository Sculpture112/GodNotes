# P2089 烤鸡## 题目背景猪猪 Hanke 得到了一只鸡。## 题目描述猪猪 Hanke 特别喜欢吃烤鸡（本是同畜牲，相煎何太急！）Hanke 吃鸡很特别，为什么特别呢？因为他有 $10$ 种配料（芥末、孜然等），每种配料可以放 $1$ 到 $3$ 克，任意烤鸡的美味程度为所有配料质量之和。现在， Hanke 想要知道，如果给你一个美味程度 $n$ ，请输出这 $10$ 种配料的所有搭配方案。## 输入格式一个正整数 $n$，表示美味程度。## 输出格式第一行，方案总数。第二行至结束，$10$ 个数，表示每种配料所放的质量，按字典序排列。如果没有符合要求的方法，就只要在第一行输出一个 $0$。## 输入输出样例 #1### 输入 #1```11```### 输出 #1```101 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 2 1 1 1 1 1 1 1 1 1 ```## 说明/提示对于 $100\%$ 的数据，$n \leq 10000$。

```

```cpp

# include <bits/stdc++.h>

using namespace std;
// #define int long long
// const int N = ;
struct scheme{
    int a[10];
};

void solve()
{
    int n;cin>>n;

    if(n<10 ||n>30){
        cout<< 0 <<endl;
        return;
    }

    vector<scheme> results;
    for(int a =1;a<=3;++a)
    for(int b =1;b<=3;b++)
    for(int c =1;c<=3;c++)
    for(int d =1;d<=3;d++)
    for(int e =1;e<=3;e++)
    for(int f =1;f<=3;f++)
    for(int g =1;g<=3;g++)
    for(int h =1;h<=3;h++)
    for(int i =1;i<=3;i++)
    for(int j =1;j<=3;j++){
        if(a+b+c+d+e+f+g+h+i+j ==n){
            results.push_back({a,b,c,d,e,f,g,h,i,j});
        }
    }

    cout<< results.size()<<endl;
    for(auto &s :results){
        for(int k =0;k<10;k++){
            cout<< s.a[k] <<(k == 9? "":" ");
        }
        cout<<endl;
    }

}
void solve2(){

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}