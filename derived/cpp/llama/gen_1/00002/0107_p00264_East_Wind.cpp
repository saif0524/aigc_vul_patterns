#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

const double PI = std::acos(-1.0);
const double eps = 1e-6;

struct Point {
    double x, y;
    int id;
};

bool operator<(const Point &p1, const Point &p2) {
    return p1.id < p2.id;
}

int angle(const Point &p) {
    double theta = std::atan2(p.y, p.x);
    if (theta < 0) theta += 2 * PI;
    return static_cast<int>(theta / PI * 180 + 0.5);
}

bool inRange(const Point &p, int w, int a, int d) {
    int ang = angle(p);
    if (ang < w - d / 2 || ang > w + d / 2) return false;
    double r = std::sqrt(p.x * p.x + p.y * p.y);
    return r <= a;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (true) {
        int h, r;
        std::cin >> h >> r;
        if (h == 0 && r == 0) break;

        std::vector<Point> houses(h);
        for (auto &p : houses) {
            std::cin >> p.x >> p.y;
            p.id = &p - &houses[0];
        }

        int u, m, s, du, dm, ds;
        std::cin >> u >> m >> s >> du >> dm >> ds;

        std::vector<Point> plums(u);
        for (auto &p : plums) {
            std::cin >> p.x >> p.y;
            p.id = -1;
        }

        std::vector<Point> peaches(m);
        for (auto &p : peaches) {
            std::cin >> p.x >> p.y;
            p.id = -1;
        }

        std::vector<Point> cherries(s);
        for (auto &p : cherries) {
            std::cin >> p.x >> p.y;
            p.id = -1;
        }

        std::vector<std::pair<int, int>> winds(r);
        for (auto &[w, a] : winds) {
            std::cin >> w >> a;
        }

        std::vector<int> days(h, 0);
        for (const auto &house : houses) {
            for (const auto &[w, a] : winds) {
                if (inRange(house, w, a, du) && !std::any_of(plums.begin(), plums.end(), [&](const Point &p) { return inRange(p, w, a, du); })
                    && !std::any_of(peaches.begin(), peaches.end(), [&](const Point &p) { return inRange(p, w, a, dm); })
                    && !std::any_of(cherries.begin(), cherries.end(), [&](const Point &p) { return inRange(p, w, a, ds); })) {
                    days[house.id]++;
                }
            }
        }

        if (*std::max_element(days.begin(), days.end()) == 0) {
            std::cout << "NA\n";
        } else {
            for (int i = 0; i < h; ++i) {
                if (days[i] == *std::max_element(days.begin(), days.end())) {
                    std::cout << i + 1 << " ";
                }
            }
            std::cout << "\n";
        }
    }

    return 0;
}