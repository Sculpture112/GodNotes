#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> s(h);
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }

    if (h > w)
    {
        vector<string> t(w, string(h, '0'));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                t[j][i] = s[i][j];
            }
        }
        s = t;
        swap(h, w);
    }
    ll ans = 0;
    vector<int> freq(h * w + 1, 0);
    for (int top = 0; top < h; top++)
    {
        vector<int> col(w, 0);
        for (int bottow = top; bottow < h; bottow++)
        {
            for (int j = 0; j < w; j++)
            {
                col[j] += s[bottow][j] - '0';
            }

            vector<int> touched;
            auto addfreq = [&](int x)
            {
                if (freq[x] == 0)
                {
                    touched.push_back(x);
                }
                freq[x]++;
            };

            addfreq(0);
            int fresum = 0;
            for (int j = 0; j < w; j++)
            {
                fresum += col[j];
                if (fresum >= k)
                {
                    ans += freq[fresum - k];
                }
                addfreq(fresum);
            }

            for (int x : touched)
            {
                freq[x] = 0;
            }
        }
    }
    cout << ans;

    return 0;
}