# []

> **原题链接:** ()

**涉及知识点:** [[]], [[]]，[[补题]],[[]],[[]]

**核心套路:** 

## 破题切入点 (思维闪念)
[]



```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 4e18;

#define all(x) (x).begin(), (x).end()

using Score = vector<int>;

int get_rank(char c) {
    if ('2' <= c && c <= '9') return c - '0';
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    return 14;
}

int get_suit(char c) {
    if (c == 'C') return 0;
    if (c == 'D') return 1;
    if (c == 'H') return 2;
    return 3;
}

int get_card(const string& s) {
    return get_suit(s[1]) * 13 + get_rank(s[0]) - 2;
}

Score get_score(vector<int> cards) {
    vector<int> rank, suit;
    int cnt[15]{};
    for (int card : cards) {
        int r = card % 13 + 2;
        rank.push_back(r);
        suit.push_back(card / 13);
        ++cnt[r];
    }

    sort(rank.rbegin(), rank.rend());
    bool flush = count(all(suit), suit[0]) == 5;

    vector<int> distinct = rank;
    distinct.erase(unique(all(distinct)), distinct.end());
    int straight_high = 0;
    if (distinct.size() == 5 && distinct[0] - distinct[4] == 4) {
        straight_high = distinct[0];
    }
    if (distinct == vector<int>({14, 5, 4, 3, 2})) {
        straight_high = 5;
    }

    vector<pair<int, int>> groups;
    for (int r = 2; r <= 14; ++r) {
        if (cnt[r]) groups.push_back({cnt[r], r});
    }
    sort(groups.rbegin(), groups.rend());

    if (flush && straight_high) return {8, straight_high};
    if (groups[0].first == 4) return {7, groups[0].second, groups[1].second};
    if (groups[0].first == 3 && groups[1].first == 2) return {6, groups[0].second, groups[1].second};
    if (flush) return {5, rank[0], rank[1], rank[2], rank[3], rank[4]};
    if (straight_high) return {4, straight_high};
    if (groups[0].first == 3) {
        Score score{3, groups[0].second};
        for (auto [count, r] : groups) {
            if (count == 1) score.push_back(r);
        }
        return score;
    }
    if (groups[0].first == 2 && groups[1].first == 2) {
        return {2, groups[0].second, groups[1].second, groups[2].second};
    }
    if (groups[0].first == 2) {
        Score score{1, groups[0].second};
        for (auto [count, r] : groups) {
            if (count == 1) score.push_back(r);
        }
        return score;
    }
    return {0, rank[0], rank[1], rank[2], rank[3], rank[4]};
}

int compare_hands(const vector<int>& me, int my_card, const vector<int>& foe, int foe_card) {
    vector<int> a = me, b = foe;
    a.push_back(my_card);
    b.push_back(foe_card);
    Score sa = get_score(a), sb = get_score(b);
    return (sa > sb) - (sa < sb);
}

pair<int, int> get_best_two(const vector<int>& four, const vector<int>& pool) {
    vector<pair<Score, int>> candidates;
    for (int card : pool) {
        vector<int> hand = four;
        hand.push_back(card);
        candidates.push_back({get_score(hand), card});
    }
    sort(candidates.begin(), candidates.end(), greater<>());
    return {candidates[0].second, candidates[1].second};
}

void solve() {
    vector<int> me(4), foe(4);
    vector<char> used(52);

    for (int i = 0; i < 4; ++i) {
        string s;
        cin >> s;
        me[i] = get_card(s);
        used[me[i]] = 1;
    }
    for (int i = 0; i < 4; ++i) {
        string s;
        cin >> s;
        foe[i] = get_card(s);
        used[foe[i]] = 1;
    }

    vector<int> pool;
    for (int card = 0; card < 52; ++card) {
        if (!used[card]) pool.push_back(card);
    }

    auto [c1, c2] = get_best_two(me, pool);
    auto [p1, ignored] = get_best_two(foe, pool);

    int against_p1 = compare_hands(me, p1 == c1 ? c2 : c1, foe, p1);
    int against_c1 = compare_hands(me, c2, foe, c1);

    if (against_p1 < 0 || against_c1 < 0) {
        cout << "GeiWoCaPiXie\n";
    } else if (against_p1 > 0 && against_c1 > 0) {
        cout << "WoYaoYanPai\n";
    } else {
        cout << "PaiMeiYouWenTi\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}

```

---


