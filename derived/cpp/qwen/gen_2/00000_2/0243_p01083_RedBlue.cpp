#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld EPS = 1e-9;

struct Point {
    ld x, y;
};

ld dist(const Point& a, const Point& b) {
    return hypot(a.x - b.x, a.y - b.y);
}

bool insideCircle(const Point& p, const Point& c, ld r) {
    return dist(p, c) < r - EPS;
}

bool validPair(const Point& r, const Point& b, const Point& c1, const Point& c2, ld r1, ld r2) {
    return !insideCircle(r, c1, r1) && !insideCircle(r, c2, r2) && !insideCircle(b, c1, r1) && !insideCircle(b, c2, r2);
}

Point intersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
    ld A1 = a2.y - a1.y, B1 = a1.x - a2.x, C1 = A1 * a1.x + B1 * a1.y;
    ld A2 = b2.y - b1.y, B2 = b1.x - b2.x, C2 = A2 * b1.x + B2 * b1.y;
    ld det = A1 * B2 - A2 * B1;
    if (fabs(det) < EPS) return {1e9, 1e9}; // parallel lines
    return {(B2 * C1 - B1 * C2) / det, (A1 * C2 - A2 * C1) / det};
}

ld circleLineIntersection(const Point& c, ld r, const Point& a1, const Point& a2) {
    Point d = {a2.x - a1.x, a2.y - a1.y};
    Point f = {a1.x - c.x, a1.y - c.y};
    ld a = d.x * d.x + d.y * d.y;
    ld b = 2 * (f.x * d.x + f.y * d.y);
    ld c = f.x * f.x + f.y * f.y - r * r;
    ld discriminant = b * b - 4 * a * c;
    if (discriminant < 0) return dist(a1, a2); // No intersection
    ld t1 = (-b - sqrt(discriminant)) / (2 * a);
    ld t2 = (-b + sqrt(discriminant)) / (2 * a);
    ld t = max(0.0, min(1.0, max(t1, t2)));
    Point p = {a1.x + t * d.x, a1.y + t * d.y};
    return min(dist(a1, a2), dist(a1, p) + dist(p, a2));
}

ld calculateCost(const Point& r, const Point& b, const Point& c1, const Point& c2, ld r1, ld r2) {
    ld d = dist(r, b);
    Point mid = {(r.x + b.x) / 2, (r.y + b.y) / 2};
    Point dir = {b.x - r.x, b.y - r.y};
    Point perp = {-dir.y, dir.x};
    Point p1 = {mid.x + perp.x, mid.y + perp.y};
    Point p2 = {mid.x - perp.x, mid.y - perp.y};
    Point i1 = intersection(r, b, c1, {c1.x + r1 * (p1.x - c1.x) / dist(c1, p1), c1.y + r1 * (p1.y - c1.y) / dist(c1, p1)});
    Point i2 = intersection(r, b, c1, {c1.x + r1 * (p2.x - c1.x) / dist(c1, p2), c1.y + r1 * (p2.y - c1.y) / dist(c1, p2)});
    Point i3 = intersection(r, b, c2, {c2.x + r2 * (p1.x - c2.x) / dist(c2, p1), c2.y + r2 * (p1.y - c2.y) / dist(c2, p1)});
    Point i4 = intersection(r, b, c2, {c2.x + r2 * (p2.x - c2.x) / dist(c2, p2), c2.y + r2 * (p2.y - c2.y) / dist(c2, p2)});
    vector<ld> distances = {d, circleLineIntersection(c1, r1, r, b), circleLineIntersection(c1, r1, b, r),
                         circleLineIntersection(c2, r2, r, b), circleLineIntersection(c2, r2, b, r)};
    ld minDist = *min_element(distances.begin(), distances.end());
    return minDist;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    Point c1, c2;
    ld r1, r2;
    cin >> c1.x >> c1.y >> r1;
    cin >> c2.x >> c2.y >> r2;
    vector<Point> red(n), blue(n);
    for(int i=0;i<n;i++) cin >> red[i].x >> red[i].y;
    for(int i=0;i<n;i++) cin >> blue[i].x >> blue[i].y;
    vector<vector<ld>> dp(1<<n, vector<ld>(1<<n, 1e18));
    dp[0][0] = 0;
    for(int maskR=0;maskR<(1<<n);maskR++){
        for(int maskB=0;maskB<(1<<n);maskB++){
            if(__builtin_popcount(maskR) != __builtin_popcount(maskB)) continue;
            for(int i=0;i<n;i++){
                if(maskR & (1<<i)){
                    bool valid = true;
                    for(int j=0;j<n;j++){
                        if(maskB & (1<<j)){
                            if(!validPair(red[i], blue[j], c1, c2, r1, r2)){
                                valid = false;
                                break;
                            }
                        }
                    }
                    if(valid){
                        for(int j=0;j<n;j++){
                            if(!(maskB & (1<<j))){
                                dp[maskR | (1<<j)][maskB | (1<<j)] = min(dp[maskR | (1<<j)][maskB | (1<<j)], dp[maskR][maskB] + calculateCost(red[i], blue[j], c1, c2, r1, r2));
                            }
                        }
                    }
                }
            }
        }
    }
    if(dp[(1<<n)-1][(1<<n)-1] > 1e17){
        cout << "Impossible";
    }
    else{
        cout << fixed << setprecision(12) << dp[(1<<n)-1][(1<<n)-1];
    }
}