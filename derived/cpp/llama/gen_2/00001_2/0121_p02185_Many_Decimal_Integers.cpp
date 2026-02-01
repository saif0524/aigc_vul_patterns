#include <iostream>
#include <string>
#include <vector>

using ll = long long;

const ll mod = 1e9 + 7;

ll pow10[200000];

ll calc(const std::string& t, const std::string& s) {
    ll res = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (t[i] == '?') {
            return -1;
        }
        res = (res * 10 + t[i] - '0') % mod;
    }
    return res;
}

void solve() {
    std::string s, t;
    std::cin >> s >> t;

    pow10[0] = 1;
    for (int i = 1; i < 200000; ++i) {
        pow10[i] = (pow10[i - 1] * 10) % mod;
    }

    std::vector<std::string> ans;
    std::string cand;

    auto dfs = [&](auto self, int i) -> void {
        if (i == t.size()) {
            if (calc(cand, s) != -1) {
                ans.push_back(cand);
            }
            return;
        }

        if (t[i] == '?') {
            for (char c = '0'; c <= '9'; ++c) {
                cand.push_back(c);
                self(self, i + 1);
                cand.pop_back();
            }
        } else {
            cand.push_back(t[i]);
            self(self, i + 1);
            cand.pop_back();
        }
    };

    dfs(dfs, 0);

    ll res = 0;
    for (auto& x : ans) {
        ll val = 0;
        for (int i = 0; i < x.size(); ++i) {
            val = (val + (x[i] - '0') * pow10[x.size() - 1 - i]) % mod;
        }
        if (val <= std::stoll(s)) {
            res = (res + val) % mod;
        }
    }

    std::cout << res << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}