#include <bits/stdc++.h>

using namespace std;

struct Character {
    int health, attack, defense, agility;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Character> characters(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> characters[i].health >> characters[i].attack >> characters[i].defense >> characters[i].agility;
    }

    sort(begin(characters), end(characters), [](const Character& a, const Character& b) {
        return a.agility > b.agility;
    });

    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + characters[i].attack - characters[0].defense;
    }

    vector<long long> dp(1 << n);
    for (int mask = 1; mask < (1 << n); ++mask) {
        int last = __builtin_ctz(mask);
        int totalDamage = prefix[last];
        if (mask == (1 << last)) {
            dp[mask] = totalDamage;
            continue;
        }
        dp[mask] = LLONG_MAX;
        for (int subMask = mask; subMask > 0; subMask = (subMask - 1) & mask) {
            int otherMask = mask ^ subMask;
            if (otherMask == 0) continue;
            dp[mask] = min(dp[mask], dp[subMask] + dp[otherMask] + totalDamage);
        }
        dp[mask] = min(dp[mask], dp[mask ^ (1 << last)] + totalDamage);
    }

    long long ans = dp.back();
    if (ans >= characters[0].health) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}