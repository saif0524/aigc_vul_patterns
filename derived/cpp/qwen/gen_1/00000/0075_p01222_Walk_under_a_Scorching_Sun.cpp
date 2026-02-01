#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const int MAX = 20;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

struct Point {
    ld x, y;
    Point() {}
    Point(ld x, ld y) : x(x), y(y) {}
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    ld dot(const Point &p) const { return x * p.x + y * p.y; }
    ld cross(const Point &p) const { return x * p.y - y * p.x; }
};

ld angle(const Point &a, const Point &b) {
    ld t = atan2l(b.cross(a), b.dot(a));
    return t < 0 ? t + 2 * PI : t;
}

ld length(const Point &a) {
    return sqrtl(a.x * a.x + a.y * a.y);
}

bool cmp(const Point &a, const Point &b, const Point &c) {
    ld v = (b - a).cross(c - a);
    return v == 0 ? length(b - a) < length(c - a) : v > 0;
}

struct Ray {
    Point O, d;
    Ray(Point O, Point d) : O(O), d(d) {}
    bool intersect(const Point &A, const Point &B, Point &res) const {
        ld v1 = (B - A).cross(O - A);
        ld v2 = (B - A).cross(O - A - d);
        if (v1 == v2) return false;
        res = A + (B - A) * (v1 / (v1 - v2));
        return true;
    }
};

struct Line {
    Point A, B;
    Line(Point A, Point B) : A(A), B(B) {}
    bool intersect(const Line &other, Point &res) const {
        ld v1 = (other.B - other.A).cross(A - other.A);
        ld v2 = (other.B - other.A).cross(B - other.A);
        if (v1 == v2) return false;
        res = other.A + (other.B - other.A) * (v1 / (v1 - v2));
        return true;
    }
};

vector<Point> buildings[MAX];
vector<pair<Point, Point>> roads;
ld theta, phi;
Point S, T;

bool inBuilding(const Point &P) {
    for (int i = 0; i < buildings.size(); i++) {
        int n = buildings[i].size();
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            Point A = buildings[i][j];
            Point B = buildings[i][(j + 1) % n];
            if (fabs((B - A).cross(P - A)) < EPS && (A - P).dot(B - P) < EPS) return true;
            if (A.y > P.y && B.y <= P.y || B.y > P.y && A.y <= P.y) {
                if ((P.y - A.y) * (B.x - A.x) > (P.x - A.x) * (B.y - A.y)) cnt++;
            }
        }
        if (cnt % 2 == 1) return true;
    }
    return false;
}

bool inSun(Point p1, Point p2, Point O, Point d) {
    Point M = (p1 + p2) / 2;
    if (!inBuilding(M)) return false;
    Ray r(O, d);
    Point q;
    if (r.intersect(p1, p2, q)) {
        if ((q - p1).dot(q - p2) < EPS) {
            return true;
        }
    }
    return false;
}

ld solve() {
    int n = buildings.size();
    int m = roads.size();
    vector<Point> nodes;
    nodes.push_back(S);
    nodes.push_back(T);
    for (auto &road : roads) {
        nodes.push_back(road.first);
        nodes.push_back(road.second);
    }
    int nn = nodes.size();
    vector<vector<ld>> dist(nn, vector<ld>(nn, 1e18));
    for (int i = 0; i < nn; i++) {
        for (int j = i + 1; j < nn; j++) {
            Point p1 = nodes[i];
            Point p2 = nodes[j];
            ld d = length(p2 - p1);
            if (!inSun(p1, p2, Point(1001, 1001), Point(cos(theta * PI / 180), sin(theta * PI / 180)))) {
                dist[i][j] = dist[j][i] = d;
            }
        }
    }
    for (int k = 0; k < nn; k++) {
        for (int i = 0; i < nn; i++) {
            for (int j = 0; j < nn; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int s = 0, t = 1;
    if (dist[s][t] >= 1e18) return -1;
    return dist[s][t];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(;;){
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        buildings.clear();
        roads.clear();
        for(int i=0;i<n;i++){
            int nv, h;
            cin >> nv >> h;
            vector<Point> v(nv);
            for(int j=0;j<nv;j++){
                cin >> v[j].x >> v[j].y;
            }
            buildings.push_back(v);
        }
        for(int i=0;i<m;i++){
            Point A, B;
            cin >> A.x >> A.y >> B.x >> B.y;
            roads.push_back({A, B});
        }
        cin >> theta >> phi;
        cin >> S.x >> S.y >> T.x >> T.y;
        ld res = solve();
        cout << fixed << setprecision(15) << res << "\n";
    }
}