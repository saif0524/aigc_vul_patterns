#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const int MAXN = 1e5 + 5;
const ld EPS = 1e-9;
const ld INF = 1e18;

struct Point {
    ld x, y;
    Point(ld _x = 0, ld _y =0) : x(_x), y(_y) {}
    Point operator-(const Point& other) const { return Point(x - other.x, y - other.y); }
    ld dot(const Point& other) const { return x * other.x + y * other.y; }
    ld cross(const Point& other) const { return x * other.y - y * other.x; }
};

vector<Point> bus[MAXN];
int n, w, v, u;

bool inside(const vector<Point>& poly, const Point& p) {
    int n = poly.size();
    bool in = false;
    for (int i = 0; i < n; i++) {
        Point a = poly[i], b = poly[(i + 1) % n];
        if ((p.y - a.y) * (b.x - a.x) < (b.y - a.y) * (p.x - a.x)) {
            if (a.y <= p.y && p.y < b.y) in = !in;
        }
        if ((p.y - b.y) * (a.x - b.x) < (a.y - b.y) * (p.x - b.x)) {
            if (b.y <= p.y && p.y < a.y) in = !in;
        }
    }
    return in;
}

bool check(ld t) {
    vector<Point> moved_bus;
    for (auto& p : bus[0]) {
        moved_bus.push_back(Point(p.x - v * t, p.y));
    }
    for (ld y = 0; y <= w; y += EPS) {
        if (!inside(moved_bus, Point(0, y))) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> w >> v >> u;
    for(int i=0;i<n;i++){
        ld x,y;
        cin >> x >> y;
        bus[0].push_back(Point(x,y));
    }
    ld lo =0, hi = INF;
    while(hi - lo > EPS){
        ld mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid;
        }
        else{
            lo = mid;
        }
    }
    cout << fixed << setprecision(10) << lo << "\n";
    return 0;
}