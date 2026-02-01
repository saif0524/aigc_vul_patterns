#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> p(n), s(n), c(k);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    for (int i = 0; i < k; i++) {
        std::cin >> c[i];
        c[i]--;
    }

    int ans = 0;
    for (int i = 0; i < k; i++) {
        int idx = c[i];
        int maxm = p[idx];
        for (int j = 0; j < n; j++) {
            if (s[j] == s[idx] && p[j] > maxm) {
                ans++;
                break;
            }
        }
    }

    std::cout << ans << std::endl;
    return 0;
}