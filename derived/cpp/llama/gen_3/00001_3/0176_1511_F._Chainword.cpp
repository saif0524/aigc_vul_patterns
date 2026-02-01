#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

const int MOD = 998244353;

std::vector<std::vector<int>> dp;
std::vector<int> lengths;
std::unordered_map<std::string, int> words;
std::vector<std::string> dictionary;

int push(std::vector<std::string>& vec, const std::string& s, int idx, int curr_len, int& id) {
    if (idx == s.size()) {
        if (vec.empty() || vec.back() != "") {
            vec.push_back("");
            return id++;
        }
        return vec.size() - 1;
    }
    if (vec.empty() || vec.back().size() + curr_len > lengths[idx]) {
        vec.push_back(s.substr(0, lengths[idx] - curr_len));
        return push(vec, s.substr(lengths[idx] - curr_len), idx + 1, 0, id);
    }
    vec.back() += s.substr(0, lengths[idx] - curr_len);
    return push(vec, s.substr(lengths[idx] - curr_len), idx, 0, id);
}

int solve(int m, int n) {
    dp.resize(m + 1, std::vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i][j] == 0) continue;
            for (const auto& word : dictionary) {
                if (i + word.size() <= m) {
                    dp[i + word.size()][j + 1] = (dp[i + word.size()][j + 1] + dp[i][j]) % MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = (ans + dp[m][i]) % MOD;
    }
    return ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    dictionary.resize(n);
    lengths.resize(n);
    for (int i = 0; i < n; i++) {
        std::cin >> dictionary[i];
        lengths[i] = dictionary[i].size();
        words[dictionary[i]] = i;
    }
    std::vector<std::string> vec;
    int id = 0;
    std::vector<int> p1(m, 0), p2(m, 0);
    for (const auto& word : dictionary) {
        int idx = push(vec, word, 0, 0, id);
        if (vec.size() > 1) {
            for (int i = 0; i < vec.size() - 1; i++) {
                p1[i] = words[vec[i]];
                p2[i] = words[vec[i + 1]];
            }
        } else {
            p1[0] = words[vec[0]];
        }
        vec.clear();
    }
    int ans = 0;
    for (const auto& word : dictionary) {
        for (int i = 0; i < m; i++) {
            ans = (ans + solve(m - i, n) * 1ll * solve(i, n)) % MOD;
        }
    }
    std::cout << ans << "\n";

    return 0;
}