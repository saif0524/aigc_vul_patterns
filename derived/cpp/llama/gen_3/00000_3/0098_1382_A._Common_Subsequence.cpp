#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, m;
        std::cin >> n >> m;

        std::vector<int> a(n);
        std::vector<int> b(m);

        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        for (int i = 0; i < m; ++i) {
            std::cin >> b[i];
        }

        std::vector<int> c;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i] == b[j]) {
                    c.push_back(a[i]);
                    break;
                }
            }
        }

        if (c.empty()) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "YES" << std::endl;
            std::cout << 1 << " " << c[0] << std::endl;
        }
    }

    return 0;
}