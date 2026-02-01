#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

int main() {
    int n, V;
    std::cin >> n >> V;

    std::vector<double> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    double minRatio = std::numeric_limits<double>::max();
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            minRatio = std::min(minRatio, b[i] / a[i]);
        }
    }

    double result = std::min(minRatio, (double)V);
    std::printf("%.9f\n", result);

    return 0;
}