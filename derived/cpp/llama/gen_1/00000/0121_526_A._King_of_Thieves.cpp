#include <iostream>
#include <string>

bool check(const std::string& s, int i1, int d) {
    int i2 = i1 + d;
    if (i2 >= s.size() || s[i2] == '.') return false;
    int i3 = i2 + d;
    if (i3 >= s.size() || s[i3] == '.') return false;
    int i4 = i3 + d;
    if (i4 >= s.size() || s[i4] == '.') return false;
    return true;
}

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    bool ans = false;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '.')
            continue;
        for (int d = 1; d <= (s.size() - i) / 4; ++d) {
            if (check(s, i, d)) {
                ans = true;
                break;
            }
        }
        if (ans)
            break;
    }
    if (ans) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }
    return 0;
}