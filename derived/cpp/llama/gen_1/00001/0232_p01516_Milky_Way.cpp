#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

using namespace std;

const long double pi = acos(-1.0L);
const long double eps = 1e-12L;

struct Point {
    long double x, y;
};

struct Star {
    Point center;
    long double angle, radius;
};

long double dist(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool intersect(const Star& a, const Star& b) {
    Point p1 = {a.center.x + a.radius * sin(a.angle * pi / 180.0L),
                a.center.y - a.radius * cos(a.angle * pi / 180.0L)};
    Point p2 = {a.center.x + a.radius * sin((a.angle + 72.0L) * pi / 180.0L),
                a.center.y - a.radius * cos((a.angle + 72.0L) * pi / 180.0L)};
    Point p3 = {b.center.x + b.radius * sin(b.angle * pi / 180.0L),
                b.center.y - b.radius * cos(b.angle * pi / 180.0L)};
    Point p4 = {b.center.x + b.radius * sin((b.angle + 72.0L) * pi / 180.0L),
                b.center.y - b.radius * cos((b.angle + 72.0L) * pi / 180.0L)};

    long double area1 = abs((p1.x * p2.y - p2.x * p1.y) + (p2.x * a.center.y - p2.y * a.center.x) +
                            (a.center.x * p1.y - a.center.y * p1.x));
    long double area2 = abs((p1.x * p3.y - p3.x * p1.y) + (p3.x * p2.y - p3.y * p2.x) +
                            (p2.x * p1.y - p2.y * p1.x));
    long double area3 = abs((p3.x * p4.y - p4.x * p3.y) + (p4.x * b.center.y - p4.y * b.center.x) +
                            (b.center.x * p3.y - b.center.y * p3.x));
    long double area4 = abs((p2.x * p4.y - p4.x * p2.y) + (p4.x * p1.y - p4.y * p1.x) +
                            (p1.x * p2.y - p1.y * p2.x));

    if (area1 + area2 + area3 + area4 < eps) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n, m, l;
    while (true) {
        cin >> n >> m >> l;
        if (n == 0 && m == 0 && l == 0) {
            break;
        }

        vector<Star> stars(n);
        for (int i = 0; i < n; i++) {
            cin >> stars[i].center.x >> stars[i].center.y >> stars[i].angle >> stars[i].radius;
        }

        vector<vector<long double>> graph(n, vector<long double>(n, numeric_limits<long double>::max()));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    graph[i][j] = 0.0L;
                } else {
                    long double distance = dist(stars[i].center, stars[j].center);
                    if (distance <= stars[i].radius + stars[j].radius + eps &&
                        intersect(stars[i], stars[j])) {
                        graph[i][j] = 0.0L;
                    } else {
                        graph[i][j] = distance;
                    }
                }
            }
        }

        vector<long double> distFromVega(n, numeric_limits<long double>::max());
        distFromVega[m - 1] = 0.0L;

        priority_queue<pair<long double, int>, vector<pair<long double, int>>, greater<pair<long double, int>>> pq;
        pq.push({0.0L, m - 1});

        while (!pq.empty()) {
            long double currDist = pq.top().first;
            int currStar = pq.top().second;
            pq.pop();

            if (currDist > distFromVega[currStar]) {
                continue;
            }

            for (int i = 0; i < n; i++) {
                long double newDist = currDist + graph[currStar][i];
                if (newDist < distFromVega[i]) {
                    distFromVega[i] = newDist;
                    pq.push({newDist, i});
                }
            }
        }

        cout << fixed;
        cout.precision(15);
        cout << distFromVega[l - 1] << endl;
    }

    return 0;
}