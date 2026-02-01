#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;
    std::string s;
    std::cin >> s;

    int x = 0, y = 0;
    for (char c : s) {
        if (c >= 'A' && c <= 'M') y++;
        else if (c >= 'N' && c <= 'Z') y--;
        else if (c >= 'a' && c <= 'm') x++;
        else if (c >= 'n' && c <= 'z') x--;
    }

    std::string ans;
    while (x > 0) {
        ans += 'a';
        x--;
    }
    while (x < 0) {
        ans += 'z';
        x++;
    }
    while (y > 0) {
        ans += 'A';
        y--;
    }
    while (y < 0) {
        ans += 'Z';
        y++;
    }

    std::cout << ans.size() << std::endl;
    std::cout << ans << std::endl;

    return 0;
}