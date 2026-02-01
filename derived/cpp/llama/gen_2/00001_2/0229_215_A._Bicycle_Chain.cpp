#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int m;
    std::cin >> m;
    std::vector<int> b(m);
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    int maxRatio = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[j] % a[i] == 0) {
                maxRatio = std::max(maxRatio, b[j] / a[i]);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[j] % a[i] == 0 && b[j] / a[i] == maxRatio) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}