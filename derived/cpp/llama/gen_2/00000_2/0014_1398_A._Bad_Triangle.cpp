#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> a(n);
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }

        bool found = false;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (a[i] + a[j] <= a[k] || a[i] + a[k] <= a[j] || a[j] + a[k] <= a[i]) {
                        std::cout << i + 1 << " " << j + 1 << " " << k + 1 << std::endl;
                        found = true;
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        if (!found) {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}