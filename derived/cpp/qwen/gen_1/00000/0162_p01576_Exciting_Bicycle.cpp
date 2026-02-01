#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld g = 9.8;

ld distance(ld x1, ld y1, ld x2, ld y2) {
    return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, V;
    cin >> N >> V;
    vector<pair<ld, ld>> points(N);
    for(int i = 0; i < N; i++){
        cin >> points[i].first >> points[i].second;
    }
    ld total_distance = 0.0;
    for(int i = 1; i < N; i++){
        ld x1 = points[i-1].first, y1 = points[i-1].second;
        ld x2 = points[i].first, y2 = points[i].second;
        ld dx = x2 - x1, dy = y2 - y1;
        ld tan_prev = (i == 1) ? 1e9 : (points[i-1].second - points[i-2].second) / (points[i-1].first - points[i-2].first);
        ld tan_curr = dy / dx;
        if(i == 1 || tan_curr < tan_prev){
            ld t_jump = (V / g) * (tan_curr + sqrtl(tan_curr * tan_curr + (2 * g * dy) / (V * V)));
            ld x_fall = x1 + V * t_jump - 0.5 * g * t_jump * t_jump / tan_curr;
            total_distance += distance(x1, y1, x_fall, y2);
        } else {
            total_distance += distance(x1, y1, x2, y2);
        }
    }
    cout << fixed << setprecision(10) << total_distance << endl;
}