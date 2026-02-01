#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, d;
    std::cin >> n >> d;

    std::vector<int> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i];
    }

    std::sort(points.begin(), points.end());

    int maxDiameter = 0;
    int left = 0, right = 0;
    int ans = n;

    while (right < n) {
        while (right < n && points[right] - points[left] <= d) {
            right++;
        }
        ans = std::min(ans, n - (right - left));
        left++;
    }

    std::cout << ans << std::endl;

    return 0;
}