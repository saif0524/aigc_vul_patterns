#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::string s;

    std::cin >> n;
    std::cin >> s;

    int cnt[2][2] = {{0, 0}, {0, 0}};

    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') {
            cnt[i % 2][0]++;
        } else {
            cnt[i % 2][1]++;
        }
    }

    int ans = std::max(cnt[0][0] + cnt[1][1], cnt[0][1] + cnt[1][0]);
    int res = n - ans;

    std::cout << res << std::endl;

    return 0;
}