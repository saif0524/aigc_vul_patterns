#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979323846

inline double rad(double deg) { return deg * PI / 180.0; }

struct Point {
    double x, y;
    Point() : x(0.0), y(0.0) {}
    Point(double x, double y) : x(x), y(y) {}
};

double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool withinSector(double angle, double theta, double degree) {
    return fabs(theta - angle) <= rad(degree / 2.0) || fabs(theta - angle + 2 * PI) <= rad(degree / 2.0) || fabs(theta - angle - 2 * PI) <= rad(degree / 2.0);
}

int main() {
    while (true) {
        int H, R;
        cin >> H >> R;
        if (H == 0 && R == 0) break;

        vector<Point> houses(H);
        for (int i = 0; i < H; ++i) cin >> houses[i].x >> houses[i].y;

        int U, M, S, du, dm, ds;
        cin >> U >> M >> S >> du >> dm >> ds;

        vector<Point> plums(U), peaches(M), cherries(S);
        for (int i = 0; i < U; ++i) cin >> plums[i].x >> plums[i].y;
        for (int i = 0; i < M; ++i) cin >> peaches[i].x >> peaches[i].y;
        for (int i = 0; i < S; ++i) cin >> cherries[i].x >> cherries[i].y;

        int ans = 0;
        vector<int> sol;

        for (int i = 0; i < H; ++i) {
            int cnt = 0;

            for (int j = 0; j < R; ++j) {
                double w, a;
                cin >> w >> a;
                w = rad(w);

                bool onlyPlum = true;

                // Check if my plum is within the sector
                Point origin(0, 0);
                double theta = atan2(houses[i].y - origin.y, houses[i].x - origin.x);
                if (dist(origin, houses[i]) > a || !withinSector(w, theta, du)) {
                    onlyPlum = false;
                    continue;
                }

                // Check other plums
                for (int u = 0; u < U; ++u) {
                    theta = atan2(houses[i].y - plums[u].y, houses[i].x - plums[u].x);
                    if (dist(houses[i], plums[u]) <= a && withinSector(w, theta, du)) {
                        onlyPlum = false;
                        break;
                    }
                }

                if (!onlyPlum) continue;

                // Check peaches
                for (int m = 0; m < M; ++m) {
                    theta = atan2(houses[i].y - peaches[m].y, houses[i].x - peaches[m].x);
                    if (dist(houses[i], peaches[m]) <= a && withinSector(w, theta, dm)) {
                        onlyPlum = false;
                        break;
                    }
                }

                if (!onlyPlum) continue;

                // Check cherries
                for (int s = 0; s < S; ++s) {
                    theta = atan2(houses[i].y - cherries[s].y, houses[i].x - cherries[s].x);
                    if (dist(houses[i], cherries[s]) <= a && withinSector(w, theta, ds)) {
                        onlyPlum = false;
                        break;
                    }
                }

                if (onlyPlum) cnt++;
            }

            if (cnt > ans) {
                ans = cnt;
                sol = {i + 1};
            } else if (cnt == ans) {
                sol.push_back(i + 1);
            }
        }

        if (ans == 0) {
            cout << "NA" << endl;
        } else {
            for (int i = 0; i < sol.size(); ++i) {
                cout << sol[i];
                if (i < sol.size() - 1) cout << " ";
            }
            cout << endl;
        }
    }

    return 0;
}