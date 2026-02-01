#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> p(n), s(n), c(k);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
    }
    for (int i = 0; i < k; ++i) {
        std::cin >> c[i];
    }

    std::vector<int> max_p(m, 0);
    for (int i = 0; i < n; ++i) {
        max_p[s[i] - 1] = std::max(max_p[s[i] - 1], p[i]);
    }

    int ans = 0;
    for (int i = 0; i < k; ++i) {
        int id = c[i] - 1;
        if (p[id] != max_p[s[id] - 1]) {
            ++ans;
        }
    }

    std::cout << ans << std::endl;
    return 0;
}