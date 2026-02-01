#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int p, v;
            std::cin >> p >> v;
            a[p - 1] = v;
        } else {
            int l, r, z;
            std::cin >> l >> r >> z;
            long long ans = 0;
            for (int j = l - 1; j < r; j++) {
                int remainder = (j - l + 1) % z;
                if (remainder == 0) remainder = z;
                ans += a[j] * remainder;
            }
            std::cout << ans << std::endl;
        }
    }
    return 0;
}