#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> a[i][j];
        }
    }

    std::vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cnt[a[i][1]]++;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[a[i][2]] == 1) {
            ans++;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}