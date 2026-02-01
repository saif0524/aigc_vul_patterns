#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int main() {
    int n, d;
    std::cin >> n >> d;

    std::vector<int> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i];
    }

    std::sort(points.begin(), points.end());

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && points[j] - points[i] <= d) {
            j++;
        }
        ans = std::min(ans, n - (j - i));
    }

    std::cout << ans << std::endl;

    return 0;
}