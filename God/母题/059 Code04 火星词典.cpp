#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string alienOrder(vector<string> &words)
    {
        vector<int> indegree(26);
        for (auto word : words)
        {
            for (char c : word)
            {
                indegree[c - 'a'] = 0;
            }
        }

        vector<vector<int>> graph(words.size());
        for (int i = 0, j; i < words.size() - 1; i++)
        {
            string cur = words[i];
            string nxt = words[i + 1];

            j = 0;
            int len = min(cur.size(), nxt.size());
            for (; j < len; j++)
            {
                if (cur[j] != nxt[j])
                {
                    graph[cur[j] - 'a'].push_back(nxt[j]-'a');
                    indegree[nxt[j]-'a']++;
                    break;
                }
            }
            if (j < cur.size() && j == nxt.size())
            {
                return "";
            }
        }

        vector<int> queue(26);

        int l = 0, r = 0;
        int kind = 0;
        for (int i = 0; i < 26; i++)
        {
            if (indegree[i] == 0)
            {
                queue[r++] = i;
            }
            if (indegree[i] != -1)
            {
                kind++;
            }
        }

        string ans;
        while (l < r)
        {
            int cur = queue[l++];
            ans.push_back(cur + 'a');
            for (int nxt : graph[cur])
            {
                if (--indegree[nxt] == 0)
                {
                    queue[r++] = nxt;
                }
            }
        }
        return ans.size() == kind ? ans : "";
    }
};