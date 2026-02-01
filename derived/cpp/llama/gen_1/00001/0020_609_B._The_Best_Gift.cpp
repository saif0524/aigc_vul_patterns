#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::vector<int> cnt(m, 0);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        --a[i]; // 0-indexing
        ++cnt[a[i]];
    }

    long long res = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            res += static_cast<long long>(cnt[i]) * cnt[j];
        }
    }

    std::cout << res << std::endl;
    return 0;
}