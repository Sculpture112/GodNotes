```cpp
现有 NN 篇文档，每篇文档由若干小写字母单词组成。记第 ii 篇文档的单词集合为 SiSi​。现给定 MM 个查询单词 w1,w2,…,wMw1​,w2​,…,wM​，请分别求出每个 wjwj​ 所在的文档编号集合。输入描述：第一行包含两个整数 N (1≦N≦103)N (1≦N≦103)。接下来 NN 行，第 ii 行首先给出整数 Li (1≦Li, ∑i=1NLi≦5×105)Li​ (1≦Li​, ∑i=1N​Li​≦5×105)，随后给出 LiLi​ 个由小写字母组成的单词，单词间以空格分隔。接着一行一个整数 M ( 1≦M≦104)M ( 1≦M≦104)。随后 MM 行，每行包含一个由小写字母组成的查询单词 wjwj​。输出描述：对于每个查询单词 wjwj​，输出一行，按升序列出所有满足 wj∈Siwj​∈Si​ 的文档编号 ii，编号间以空格分隔；若对应集合为空，则输出空行。示例1输入：3
5 hello world this is test
4 sample test case data
3 test world data
4
test
data
hello
missing
```
复制

输出：
```cpp
1 2 3
2 3
1
```
复制

示例2

输入：
```cpp
2
3 a b a
2 x y
2
b
z
```
复制

输出：
```cpp
1
```

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;

    map<string, set<int>> invertedIndex;

    for(int i = 1;i<=n;++i){
        int Li;
        cin>>Li;
        while(Li--){
            string word;cin>>word;
            invertedIndex[word].insert(i);
        }
    }
    int m;
    cin>>m;
    while(m--){
        string query;cin>>query;

        if(invertedIndex.count(query)){
            const set<int>& docIds = invertedIndex[query];
            for(auto it = docIds.begin();it != docIds.end();++it){
                cout<<(it == docIds.begin() ? "":" ")<<*it;
            }
        }
        cout<<endl;
    }
}
// 64 位输出请用 printf("%lld")
```