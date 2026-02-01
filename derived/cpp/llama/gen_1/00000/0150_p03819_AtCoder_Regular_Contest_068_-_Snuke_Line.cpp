#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> v(m + 1);

    for (int i = 0; i < n; ++i) {
        int l, r;
        std::cin >> l >> r;
        v[l - 1].push_back(r);
    }

    for (int d = 1; d <= m; ++d) {
        int ans = 0;
        for (int i = 0; i <= m; i += d) {
            for (const auto& right : v[i]) {
                if (right >= i) {
                    ++ans;
                }
            }
        }
        std::cout << ans << std::endl;
    }

    return 0;
}