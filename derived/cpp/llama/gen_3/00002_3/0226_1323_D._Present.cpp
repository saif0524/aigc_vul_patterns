#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::mt19937 rng(std::random_device{}());
    std::shuffle(a.begin(), a.end(), rng);
    int ans = 0;
    for (int b = 0; b < 25; b++) {
        std::vector<int> cnt(1 << b, 0);
        for (int i = 0; i < n; i++) {
            cnt[a[i] % (1 << b)]++;
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int res = 0;
            for (int k = 0; k <= b; k++) {
                res += cnt[((1 << k) - 1) ^ (a[i] % (1 << (k + 1)) >> k)];
            }
            for (int k = b + 1; k <= 2 * b; k++) {
                res += cnt[(1 << (k - b)) - 1 - (a[i] % (1 << (k - b)) >> b)];
            }
            sum ^= (res & 1);
        }
        if (sum) {
            ans += 1 << b;
        }
    }
    std::cout << ans << "\n";
    return 0;
}