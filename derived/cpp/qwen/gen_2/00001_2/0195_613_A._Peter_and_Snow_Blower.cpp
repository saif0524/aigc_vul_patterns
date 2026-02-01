#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll cross(pll a, pll b) {
    return a.first * b.second - a.second * b.first;
}

double polygonArea(vector<pll>& points) {
    int n = points.size();
    double area = 0.0;
    for (int i = 0; i < n; ++i) {
        area += cross(points[i], points[(i + 1) % n]);
    }
    return fabs(area) / 2.0;
}

double distance(pll a, pll b) {
    ll dx = a.first - b.first;
    ll dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n;
    pll P;
    cin >> n >> P.first >> P.second;
    vector<pll> polygon(n);
    for (auto& p : polygon) {
        cin >> p.first >> p.second;
    }
    
    double minRadius = INFINITY;
    for (const auto& p : polygon) {
        minRadius = min(minRadius, distance(P, p));
    }
    
    double area = polygonArea(polygon);
    double totalArea = area + M_PI * minRadius * minRadius;
    
    cout << fixed << setprecision(15) << totalArea << endl;
    
    return 0;
}