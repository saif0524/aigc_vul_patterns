#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long double ld;

int main(){
    int n;
    ld Px, Py;
    cin >> n >> Px >> Py;
    vector<pair<ld, ld>> points(n);
    for(auto &p : points) cin >> p.first >> p.second;
    points.push_back(points[0]);
    ld polygon_area = 0;
    for(int i = 0; i < n; i++){
        polygon_area += (points[i].first * points[i+1].second) - (points[i+1].first * points[i].second);
    }
    polygon_area = fabsl(polygon_area) / 2.0;
    ld outer_radius_sq = 0, inner_radius_sq = 1e18;
    for(int i = 0; i < n; i++){
        ld Ox = points[i].first, Oy = points[i].second;
        ld outer_distance_sq = (Ox - Px) * (Ox - Px) + (Oy - Py) * (Oy - Py);
        outer_radius_sq = max(outer_radius_sq, outer_distance_sq);
        ld inner_distance_sq = ((Ox + points[i+1].first) / 2.0 - Px) * ((Ox + points[i+1].first) / 2.0 - Px) + 
                             ((Oy + points[i+1].second) / 2.0 - Py) * ((Oy + points[i+1].second) / 2.0 - Py);
        inner_radius_sq = min(inner_radius_sq, inner_distance_sq);
    }
    ld outer_radius = sqrtl(outer_radius_sq);
    ld inner_radius = sqrtl(inner_radius_sq);
    ld circle_area = M_LN2 * (outer_radius * outer_radius - inner_radius * inner_radius);
    ld total_area = polygon_area * 2 + circle_area;
    cout << total_area;
}