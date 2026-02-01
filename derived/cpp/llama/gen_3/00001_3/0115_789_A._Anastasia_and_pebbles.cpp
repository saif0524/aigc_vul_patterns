#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> w(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }

    std::sort(w.rbegin(), w.rend());

    int ans = 0;
    int p1 = 0, p2 = 0;

    for (int i = 0; i < n; i++) {
        if (p1 < p2) {
            std::swap(p1, p2);
        }
        if (p1 + w[i] <= k) {
            p1 += w[i];
        } else {
            ans++;
            p1 = w[i];
        }
        p2 = 0;
    }

    if (p1 > 0 || p2 > 0) {
        ans++;
    }

    std::cout << ans << std::endl;

    return 0;
}