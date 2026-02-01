#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Point {
    int x, y;
};

int main() {
    int H, W;
    std::cin >> H >> W;

    std::vector<std::string> s(H);
    for (int i = 0; i < H; i++) {
        std::cin >> s[i];
    }

    std::vector<Point> points;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (s[i][j] == '#') {
                points.push_back({i, j});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            int d = std::abs(points[i].x - points[j].x) + std::abs(points[i].y - points[j].y);
            for (int k = j + 1; k < points.size(); k++) {
                if (std::abs(points[i].x - points[k].x) + std::abs(points[i].y - points[k].y) == d &&
                    std::abs(points[j].x - points[k].x) + std::abs(points[j].y - points[k].y) == d) {
                    ans++;
                }
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}