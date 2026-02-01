#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld PI = acos(-1.0);

struct Point {
    ld x, y;
};

ld distance(const Point& a, const Point& b) {
    return hypot(a.x - b.x, a.y - b.y);
}

ld polygonArea(vector<Point>& points) {
    int n = points.size();
    ld area = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += points[i].x * points[j].y;
        area -= points[j].x * points[i].y;
    }
    area = fabs(area) / 2.0;
    return area;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    Point P;
    cin >> n >> P.x >> P.y;
    vector<Point> polygon(n);
    for(auto &p: polygon){
        cin >> p.x >> p.y;
    }
    ld radius = 0;
    for(const auto &p: polygon){
        radius = max(radius, distance(p, P));
    }
    ld polygonAreaValue = polygonArea(polygon);
    ld totalArea = polygonAreaValue + 2 * PI * radius * radius;
    cout << fixed << setprecision(16) << totalArea << "\n";
}