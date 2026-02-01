#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    std::cin >> n >> s;

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '#' && s[i + 1] == '.') {
            ans++;
        }
    }

    int b = 0, w = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') {
            b++;
        } else {
            w++;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '#') {
            cnt++;
        } else {
            cnt = 0;
        }
        b = std::min(b, cnt);
    }

    cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '.') {
            cnt++;
        } else {
            cnt = 0;
        }
        w = std::min(w, cnt);
    }

    std::cout << std::min(ans, std::min(b, w)) << std::endl;

    return 0;
}