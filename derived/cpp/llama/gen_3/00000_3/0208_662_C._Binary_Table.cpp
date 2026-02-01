#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int MOD = 1e9 + 7;
const int INF = 1e9 + 9;

int n, m;
std::vector<std::string> table;
std::vector<int> sums;

void input() {
    std::cin >> n >> m;
    table.resize(n);
    for (auto& row : table) {
        std::cin >> row;
    }
}

int solve() {
    int res = INF;
    for (int mask = 0; mask < (1 << n); mask++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            int ones = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    ones += table[i][j] == '0';
                } else {
                    ones += table[i][j] == '1';
                }
            }
            cnt += std::min(ones, n - ones);
        }
        res = std::min(res, cnt);
    }
    return res;
}

void output(int res) {
    std::cout << res << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    input();
    output(solve());
    return 0;
}