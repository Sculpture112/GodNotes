#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

bool canConvert(string str1, string str2)
{
    if(str1 == str2)
        return true;

    int map[26];
    fill(map, map + 26, 0);

    int kinds = 0;
    for (int i = 0; i < str2.length();i++){
        if(map[str2[i] - 'a']++ == 0){
            kinds++;
        }
    }
    if(kinds == 26)
        return false;

    fill(map, map + 26, -1);
    for (int i = 0,cur; i < str1.length();i++){
        cur = str1[i] - 'a';
        if(map[cur] != -1 && str2[map[cur]] != str2[i]){
            return false;
        }
        map[cur] = i;
    }
    return true;
}