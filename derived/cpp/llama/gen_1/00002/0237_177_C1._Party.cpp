#include <iostream>
#include <vector>
#include <utility>
#include <bitset>

const int MAX_N = 2005;

std::vector<std::vector<int>> friends(MAX_N);
std::vector<std::vector<int>> enemies(MAX_N);
std::vector<bool> visited(MAX_N);

int n;

void dfs(int u, std::bitset<MAX_N>& mask, std::vector<int>& travel) {
    visited[u] = true;
    travel.push_back(u);

    for (auto v : friends[u]) {
        if (!mask[v]) continue;
        if (visited[v]) continue;
        dfs(v, mask, travel);
    }
}

int check(std::bitset<MAX_N> mask) {
    int cc = 0;
    for (int i = 1; i <= n; ++i) {
        if (!mask[i]) continue;
        if (visited[i]) continue;

        std::vector<int> travel;
        dfs(i, mask, travel);

        bool ok = true;
        for (auto p : travel) {
            for (auto q : enemies[p]) {
                if (mask[q]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }

        if (ok) ++cc;
    }

    for (int i = 1; i <= n; ++i) visited[i] = false;

    return cc;
}

int solve() {
    int ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        std::bitset<MAX_N> bit_mask;
        bit_mask.reset();
        bit_mask |= mask;

        int cnt = check(bit_mask);
        if (cnt == 1) {
            int cnt_ones = 0;
            for (int i = 1; i <= n; ++i) {
                if (bit_mask[i]) ++cnt_ones;
            }
            ans = std::max(ans, cnt_ones);
        }
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> n;
    int k;
    std::cin >> k;
    while (k--) {
        int u, v;
        std::cin >> u >> v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }

    int m;
    std::cin >> m;
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        enemies[u].push_back(v);
        enemies[v].push_back(u);
    }

    std::cout << solve() << std::endl;

    return 0;
}