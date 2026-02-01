#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool check(const std::string& s) {
    int cnt = 0;
    for (char c : s) {
        if (c == '(') ++cnt;
        else --cnt;
        if (cnt < 0) return false;
    }
    return cnt == 0;
}

std::string solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::string ans = s;
    for (int i = 0; i < n; ++i) {
        std::string t = s.substr(i, n - i) + s.substr(0, i);
        if (!check(t)) {
            int cnt = 0;
            for (char c : t) {
                if (c == '(') ++cnt;
                else --cnt;
            }
            t += std::string(std::abs(cnt), (cnt < 0 ? '(' : ')'));
            if (t.size() < ans.size() || (t.size() == ans.size() && t < ans))
                ans = t;
        } else if (t.size() < ans.size() || (t.size() == ans.size() && t < ans))
            ans = t;
    }
    return ans;
}

int main() {
    std::cout << solve() << std::endl;
    return 0;
}