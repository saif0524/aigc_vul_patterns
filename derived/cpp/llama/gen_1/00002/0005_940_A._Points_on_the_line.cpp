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

    int minPointsToRemove = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int pointsToRemove = 0;
            int left = i, right = j;
            for (int k = 0; k < n; k++) {
                if (points[k] < points[left] || points[k] > points[right]) {
                    pointsToRemove++;
                } else if (points[right] - points[left] > d) {
                    if (k < left) {
                        pointsToRemove++;
                    } else if (k > right) {
                        pointsToRemove++;
                    } else {
                        if (points[right] - points[left] - points[k] + points[left] <= d &&
                            points[right] - points[left] - points[right] + points[k] <= d) {
                            pointsToRemove++;
                        }
                    }
                }
            }
            if (points[right] - points[left] > d) {
                pointsToRemove++;
            }
            minPointsToRemove = std::min(minPointsToRemove, pointsToRemove);
        }
    }

    std::cout << minPointsToRemove << std::endl;

    return 0;
}