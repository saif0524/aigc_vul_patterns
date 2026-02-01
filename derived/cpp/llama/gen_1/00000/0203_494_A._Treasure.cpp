#include <iostream>
#include <string>
#include <vector>

void solve() {
    std::string s;
    std::cin >> s;

    std::vector<int> ans;
    int pen = s.size() - 1;
    while (s[pen] != '#') {
        --pen;
    }

    int cnt = 0, open = 0, close = 0;
    for (int i = 0; i < pen; ++i) {
        if (s[i] == '(') {
            ++open;
        } else {
            ++close;
        }
    }

    close += open - close;

    cnt = close;
    for (int i = pen - 1; i >= 0; --i) {
        if (s[i] == '#') {
            ans.push_back(1);
            --cnt;
        } else if (s[i] == ')') {
            --cnt;
        } else {
            --open;
            ++cnt;
        }
    }

    if (open > 0 || cnt > 0) {
        std::cout << -1 << std::endl;
    } else {
        for (auto x : ans) {
            std::cout << x << std::endl;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}