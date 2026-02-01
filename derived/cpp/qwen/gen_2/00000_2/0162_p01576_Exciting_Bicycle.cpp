#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld g = 9.8;

pair<ld, ld> solveQuadratic(ld a, ld b, ld c) {
    ld D = b * b - 4 * a * c;
    if (D < 0) return {LD_MAX, LD_MAX};
    ld sqrtD = sqrt(D);
    return {(-b + sqrtD) / (2 * a), (-b - sqrtD) / (2 * a)};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, V;
    cin >> N >> V;
    vector<pair<int, int>> points(N);
    for(auto &p : points) cin >> p.first >> p.second;
    ld total_length = 0;
    for(int i = 1; i < N ; i++) {
        int x1 = points[i-1].first, y1 = points[i-1].second;
        int x2 = points[i].first, y2 = points[i].second;
        ld dx = x2 - x1, dy = y2 - y1;
        ld slope = dy / dx;
        ld prev_slope = (i > 1) ? (ld)(y1 - points[i-2].second) / (x1 - points[i-2].first) : -1;
        if(slope > prev_slope) {
            ld t = 2 * V / g;
            ld y_max = V * V / (2 * g);
            ld h = y1 - (y_max - 0.5 * g * (V/g) * (V/g));
            ld a = -0.5 * g;
            ld b = V - slope;
            ld c = h - y1;
            auto roots = solveQuadratic(a, b, c);
            ld t1 = roots.first, t2 = roots.second;
            ld t_solution = min(t1, t2);
            ld x_jump = V * t_solution;
            ld x_fall = x_solution * (V - slope) / (slope - V + g * t_solution);
            ld x_total = x_jump + x_fall;
            total_length += x_total;
        } else {
            total_length += dx;
        }
    }
    cout << fixed << setprecision(10) << total_length << "\n";
    return 0;
}