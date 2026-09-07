# []

> **原题链接:** ()

**涉及知识点:** [[博弈论]], [[完全信息顺序博弈]]，[[补题]],[[]],[[]]

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

// Score 是一手五张牌的“牌力数组”。
// 第一个数表示牌型等级，后面的数按牌型规则表示关键点数。
// vector<int> 的字典序比较正好可以完成两手牌的比较。
using Score = vector<int>;

int get_rank(char c) {
    // 将牌面字符统一转换成整数，方便排序和比较。
    if ('2' <= c && c <= '9') return c - '0';
    if (c == 'T') return 10;
    if (c == 'J') return 11;
    if (c == 'Q') return 12;
    if (c == 'K') return 13;
    return 14;
}

int get_suit(char c) {
    // 花色本身没有大小，只需要用不同整数区分四种花色。
    if (c == 'C') return 0;
    if (c == 'D') return 1;
    if (c == 'H') return 2;
    return 3;
}

int get_card(const string& s) {
    // 一张牌的编号 = 花色编号 * 13 + 点数编号。
    // 因此编号范围是 0..51，后面可以用 /13 和 %13 还原花色、点数。
    return get_suit(s[1]) * 13 + get_rank(s[0]) - 2;
}

Score get_score(vector<int> cards) {
    vector<int> rank, suit;
    int cnt[15]{}; // cnt[x] 表示点数 x 出现了几次。

    // 将五张牌的编号拆成点数、花色，并统计重复点数。
    for (int card : cards) {
        int r = card % 13 + 2;
        rank.push_back(r);
        suit.push_back(card / 13);
        ++cnt[r];
    }

    // 从大到小排列点数，方便处理高牌、同花和踢脚牌。
    sort(rank.rbegin(), rank.rend());

    // 五张牌的花色都等于第一张牌的花色，说明是同花。
    bool flush = count(all(suit), suit[0]) == 5;

    // 去掉重复点数，后面用它判断是否为顺子。
    vector<int> distinct = rank;
    distinct.erase(unique(all(distinct)), distinct.end());

    // straight_high == 0 表示不是顺子；否则表示顺子的最高点数。
    int straight_high = 0;
    if (distinct.size() == 5 && distinct[0] - distinct[4] == 4) {
        straight_high = distinct[0];
    }

    // A、2、3、4、5 是特殊顺子，A 在这里按 1 使用。
    if (distinct == vector<int>({14, 5, 4, 3, 2})) {
        straight_high = 5;
    }

    // 将每个出现过的点数整理成 {出现次数, 点数}。
    vector<pair<int, int>> groups;
    for (int r = 2; r <= 14; ++r) {
        if (cnt[r]) groups.push_back({cnt[r], r});
    }
    // 先按出现次数从大到小，再按点数从大到小。
    // 这样 groups[0] 永远是最重要的重复点数。
    sort(groups.rbegin(), groups.rend());

    // 按牌型强弱从高到低判断，避免同花顺被误判成同花或顺子。
    // 返回数组的第一个数是牌型等级，等级越大越强。
    if (flush && straight_high) return {8, straight_high};
    if (groups[0].first == 4) return {7, groups[0].second, groups[1].second};
    if (groups[0].first == 3 && groups[1].first == 2) return {6, groups[0].second, groups[1].second};
    if (flush) return {5, rank[0], rank[1], rank[2], rank[3], rank[4]};
    if (straight_high) return {4, straight_high};

    if (groups[0].first == 3) {
        // 三条：先比较三条点数，再比较两张单牌。
        Score score{3, groups[0].second};
        for (auto [count, r] : groups) {
            if (count == 1) score.push_back(r);
        }
        return score;
    }
    if (groups[0].first == 2 && groups[1].first == 2) {
        // 两对：大对、小对、最后的单牌依次比较。
        return {2, groups[0].second, groups[1].second, groups[2].second};
    }
    if (groups[0].first == 2) {
        // 一对：先比较对子点数，再比较三张踢脚牌。
        Score score{1, groups[0].second};
        for (auto [count, r] : groups) {
            if (count == 1) score.push_back(r);
        }
        return score;
    }
    // 前面都不满足时就是高牌，五张点数从大到小比较。
    return {0, rank[0], rank[1], rank[2], rank[3], rank[4]};
}

int compare_hands(const vector<int>& me, int my_card, const vector<int>& foe, int foe_card) {
    // 只比较当前这一局：双方各把指定暗牌补到自己的四张明牌上。
    vector<int> a = me, b = foe;
    a.push_back(my_card);
    b.push_back(foe_card);
    Score sa = get_score(a), sb = get_score(b);

    // bool 会自动转换成 0/1：
    // 你赢返回 1，平局返回 0，你输返回 -1。
    return (sa > sb) - (sa < sb);
}

pair<int, int> get_best_two(const vector<int>& four, const vector<int>& pool) {
    // 对固定的四张明牌，枚举每一张候选暗牌后的牌力。
    vector<pair<Score, int>> candidates;
    for (int card : pool) {
        vector<int> hand = four;
        hand.push_back(card);
        candidates.push_back({get_score(hand), card});
    }
    // 按牌力从强到弱排序，前两项就是最强和次强的补牌。
    sort(candidates.begin(), candidates.end(), greater<>());
    return {candidates[0].second, candidates[1].second};
}

void solve() {
    vector<int> me(4), foe(4);
    vector<char> used(52);

    // 读入你的四张明牌，并标记这些牌已经被使用。
    for (int i = 0; i < 4; ++i) {
        string s;
        cin >> s;
        me[i] = get_card(s);
        used[me[i]] = 1;
    }
    // 读入法国赌神的四张明牌，同样标记为已使用。
    for (int i = 0; i < 4; ++i) {
        string s;
        cin >> s;
        foe[i] = get_card(s);
        used[foe[i]] = 1;
    }

    // 没有出现在八张明牌中的牌，就是双方可以选择的 44 张候选暗牌。
    vector<int> pool;
    for (int card = 0; card < 52; ++card) {
        if (!used[card]) pool.push_back(card);
    }

    // c1、c2：你的最强和次强补牌；p1：法国赌神的最强补牌。
    auto [c1, c2] = get_best_two(me, pool);
    auto [p1, ignored] = get_best_two(foe, pool);

    // 情况一：法国赌神选择自己的最强牌 p1。
    // 如果 p1 恰好就是 c1，你只能选择 c2，否则可以选择 c1。
    int against_p1 = compare_hands(me, p1 == c1 ? c2 : c1, foe, p1);

    // 情况二：法国赌神抢走你的最强牌 c1，你只能使用 c2。
    int against_c1 = compare_hands(me, c2, foe, c1);

    // 只要法国赌神有一种策略能赢，他就能保证获胜。
    if (against_p1 < 0 || against_c1 < 0) {
        cout << "GeiWoCaPiXie\n";
    // 两种关键策略下你都能赢，才是你能保证获胜。
    } else if (against_p1 > 0 && against_c1 > 0) {
        cout << "WoYaoYanPai\n";
    // 其他情况双方都不能保证获胜，结果是平局。
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


