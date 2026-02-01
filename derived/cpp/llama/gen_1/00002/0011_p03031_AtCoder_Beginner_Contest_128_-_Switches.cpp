#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> k_s(M);
    for (int i = 0; i < M; ++i) {
        int k;
        std::cin >> k;
        k_s[i].resize(k + 1);
        k_s[i][0] = k;
        for (int j = 1; j <= k; ++j) {
            std::cin >> k_s[i][j];
        }
    }

    std::vector<int> p(M);
    for (int i = 0; i < M; ++i) {
        std::cin >> p[i];
    }

    int ans = 0;
    for (int mask = 0; mask < (1 << N); ++mask) {
        bool ok = true;
        for (int i = 0; i < M; ++i) {
            int cnt = 0;
            for (int j = 1; j <= k_s[i][0]; ++j) {
                if (mask & (1 << (k_s[i][j] - 1))) {
                    cnt++;
                }
            }
            if ((cnt % 2) != p[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}