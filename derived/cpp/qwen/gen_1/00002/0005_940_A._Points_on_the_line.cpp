#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, d;
    std::cin >> n >> d;
    std::vector<int> points(n);
    for (int &x : points) std::cin >> x;
    std::sort(points.begin(), points.end());

    int min_removals = n;
    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        while (j < n && points[j] - points[i] <= d) ++j;
        min_removals = std::min(min_removals, n - (j - i));
    }

    std::cout << min_removals;
    return 0;
}