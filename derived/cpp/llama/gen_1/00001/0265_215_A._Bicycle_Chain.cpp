#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    int m;
    std::cin >> m;
    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    double maxRatio = 0.0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            double ratio = static_cast<double>(b[j]) / a[i];
            if (ratio == static_cast<int>(ratio)) {
                if (ratio > maxRatio) {
                    maxRatio = ratio;
                    count = 1;
                } else if (ratio == maxRatio) {
                    count++;
                }
            }
        }
    }

    std::cout << count << std::endl;
    return 0;
}