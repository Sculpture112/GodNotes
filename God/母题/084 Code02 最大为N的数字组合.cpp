#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

class Solution
{
public:
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        int len = 1;
        int offset = 1;
        int tmp = n / 10;
        while(tmp>0){
            tmp /= 10;
            offset *= 10;
            len++;
        }

        vector<int> digit(digits.size());
        for (int i = 0; i < digits.size(); i++) {
            digit[i] = stoi(digits[i]);
        }

        return f(digit, len, n, offset, 0, 0);
    }

    int f(vector<int>& digit,int len,int num,int offset,int free,int fix)
    {
        if(len == 0){
            return fix == 1 ? 1 : 0;
        }
        int ans = 0;
        int cur = num / offset % 10;
        if (fix == 0)
        {
            ans += f(digit, len-1, num, offset / 10, 1, 0);
        }

        if(free ==0){
            for(int x:digit){

                if(x<cur){
                    ans += f(digit, len-1, num, offset / 10, 1, 1);
                }
                else if(x==cur){
                    ans += f(digit, len - 1, num, offset / 10, 0, 1);
                }
                else
                    break;
            }
        }
        else{
            ans += digit.size() * f(digit, len - 1, num, offset / 10, 1, 1);
        }
        return ans;
    }
    int atMostNGivenDigitSet2(vector<string> &digits, int n){
        int m = digits.size();
        vector<int> digit(m);
        for (int i = 0; i < n; i++) {
            digit[i] = stoi(digits[i]);
        }

        int offset = 1;
        int tmp = n / 10;
        int len = 1;
        while(tmp>0){
            tmp /= 10;
            offset *= 10;
            len++;
        }

        vector<int> cnt(len);
        int ans = 0;
        for (int i = m, k = 1; k < len; k++, i *= m)
        {
            cnt[k] = i;
            ans += i;
        }
        return f(digit, cnt, len, n, offset);
    }
    int f(vector<int>& digit,vector<int>& cnt,int len,int num,int offset)
    {
        if(len == 0)
            return 1;

        int cur = num / offset % 10;
        int ans = 0;
        for (int x : digit)
        {
            if(x<cur){
                ans += cnt[len - 1];
            }
            else if(x==cur){
                ans += f(digit, cnt, len - 1, num, offset / 10);
            }
            else
                break;
        }
        return ans;
    }
};