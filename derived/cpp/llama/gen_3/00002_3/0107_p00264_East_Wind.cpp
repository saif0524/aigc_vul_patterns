#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double PI = acos(-1.0);

struct Point {
    double x, y;
};

double angle(const Point& p) {
    return atan2(p.y, p.x);
}

double dist(const Point& p) {
    return sqrt(p.x * p.x + p.y * p.y);
}

bool inRange(const Point& p, double w, double a, double d) {
    double ang = angle(p);
    double wRad = w * PI / 180.0;
    double dRad = d * PI / 180.0;
    double aRad = a * PI / 180.0;
    double minAng = wRad - dRad / 2.0;
    double maxAng = wRad + dRad / 2.0;
    if (minAng < -PI) {
        minAng += 2 * PI;
        maxAng += 2 * PI;
    }
    if (maxAng > PI) {
        maxAng -= 2 * PI;
        minAng -= 2 * PI;
    }
    if (ang < 0) ang += 2 * PI;
    return (dist(p) <= a) && (minAng <= ang && ang <= maxAng);
}

int main() {
    int H, R;
    while (cin >> H >> R) {
        if (H == 0 && R == 0) break;
        vector<Point> houses(H);
        for (int i = 0; i < H; i++) {
            cin >> houses[i].x >> houses[i].y;
        }
        int U, M, S;
        double du, dm, ds;
        cin >> U >> M >> S >> du >> dm >> ds;
        vector<Point> plums(U), peaches(M), cherries(S);
        for (int i = 0; i < U; i++) {
            cin >> plums[i].x >> plums[i].y;
        }
        for (int i = 0; i < M; i++) {
            cin >> peaches[i].x >> peaches[i].y;
        }
        for (int i = 0; i < S; i++) {
            cin >> cherries[i].x >> cherries[i].y;
        }
        vector<pair<double, double>> winds(R);
        for (int i = 0; i < R; i++) {
            cin >> winds[i].first >> winds[i].second;
        }
        vector<int> counts(H, 0);
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < R; j++) {
                bool plum = inRange(houses[i], winds[j].first, winds[j].second, du);
                bool peach = false, cherry = false;
                for (int k = 0; k < M; k++) {
                    if (inRange({houses[i].x - peaches[k].x, houses[i].y - peaches[k].y}, winds[j].first, winds[j].second, dm)) {
                        peach = true;
                        break;
                    }
                }
                for (int k = 0; k < S; k++) {
                    if (inRange({houses[i].x - cherries[k].x, houses[i].y - cherries[k].y}, winds[j].first, winds[j].second, ds)) {
                        cherry = true;
                        break;
                    }
                }
                for (int k = 0; k < U; k++) {
                    if (inRange({houses[i].x - plums[k].x, houses[i].y - plums[k].y}, winds[j].first, winds[j].second, du)) {
                        plum = false;
                        break;
                    }
                }
                if (plum &&!peach &&!cherry) {
                    counts[i]++;
                }
            }
        }
        int maxCount = *max_element(counts.begin(), counts.end());
        if (maxCount == 0) {
            cout << "NA" << endl;
        } else {
            for (int i = 0; i < H; i++) {
                if (counts[i] == maxCount) {
                    cout << i + 1 << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}