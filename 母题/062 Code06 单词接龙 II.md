# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[需重刷]]

**难度 [[]]


```cpp
// 062 Code06 单词接龙 II

// 按字典 wordList 完成从单词 beginWord 到单词 endWord 转化
// 一个表示此过程的 转换序列 是形式上像 
// beginWord -> s1 -> s2 -> ... -> sk 这样的单词序列，并满足：
// 每对相邻的单词之间仅有单个字母不同
// 转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词
// 注意，beginWord 不必是字典 wordList 中的单词
// sk == endWord
// 给你两个单词 beginWord 和 endWord ，以及一个字典 wordList
// 请你找出并返回所有从 beginWord 到 endWord 的 最短转换序列
// 如果不存在这样的转换序列，返回一个空列表
// 每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk] 的形式返回
// 测试链接 : https://leetcode.cn/problems/word-ladder-ii/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>

using namespace std;

// 单词表
unordered_set<string> dict;
unordered_set<string> curLevel;
unordered_set<string> nextLevel;

// 反向图，用于从 endWord 倒推回 beginWord
unordered_map<string, vector<string>> graph;

// 记录路径，当生成一条有效路的时候，拷贝进 ans！
// C++ 中用 deque 完美对应 Java 的 LinkedList 处理前后端插入删除
deque<string> path;
vector<vector<string>> ans;

class Solution {
public:
    void build(vector<string>& wordList) {
        dict.clear();
        for (const string& w : wordList) {
            dict.insert(w);
        }
        graph.clear();
        ans.clear();
        curLevel.clear();
        nextLevel.clear();
        path.clear();
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        build(wordList);
        if (!dict.count(endWord)) {
            return ans;
        }
        if (bfs(beginWord, endWord)) {
            dfs(endWord, beginWord);
        }
        return ans;
    }

    // begin -> end ，一层层 bfs 去建图
    // 返回值：真的能找到 end，返回 true；否则 false
    bool bfs(const string& begin, const string& end) {
        bool find = false;
        curLevel.insert(begin);
        
        while (!curLevel.empty()) {
            // 等价于 Java 的 dict.removeAll(curLevel)
            // 必须在这一层扩展前从字典中删除当前层的词，以防走回头路保证最短路径
            for (const string& w : curLevel) {
                dict.erase(w);
            }
            
            for (const string& word : curLevel) {
                // word : 去扩
                // 每个位置，字符 a~z，换一遍！检查在词表中是否存在
                // 避免加工出自己
                string w = word;
                for (int i = 0; i < w.length(); i++) {
                    char old = w[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        w[i] = ch;
                        if (dict.count(w) && w != word) {
                            if (w == end) {
                                find = true;
                            }
                            // C++ 的 map 会自动处理不存在的键并创建空的 vector，所以可以直接 push_back
                            graph[w].push_back(word);
                            nextLevel.insert(w);
                        }
                    }
                    w[i] = old; // 回溯恢复字符
                }
            }
            
            if (find) {
                return true;
            } else {
                // 等同于交换 curLevel 和 nextLevel，并清空 nextLevel
                // 在 C++ 中 swap 是 O(1) 的高效操作
                curLevel.swap(nextLevel);
                nextLevel.clear();
            }
        }
        return false;
    }

    void dfs(const string& word, const string& aim) {
        path.push_front(word);
        if (word == aim) {
            // 利用迭代器范围构造来快速拷贝路径
            ans.push_back(vector<string>(path.begin(), path.end()));
        } else if (graph.count(word)) {
            for (const string& next_word : graph[word]) {
                dfs(next_word, aim);
            }
        }
        path.pop_front(); // 回溯状态清理
    }
};
```

---


**核心套路:** [[]]
**前置母题/相似题目:** [[]]
**时空限制瓶颈:** []

---


## 破题切入点 (思维闪念)
[]
