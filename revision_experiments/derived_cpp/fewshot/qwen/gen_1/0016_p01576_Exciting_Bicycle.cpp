#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld EPS = 1e-9;
const ld g = 9.8;

struct Point {
    ld x, y;
};

ld dist(Point a, Point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    ld V;
    cin >> N >> V;
    vector<Point> points(N);
    for(int i=0;i<N;i++){
        cin >> points[i].x >> points[i].y;
    }
    ld total_length = 0;
    for(int i=1;i<N;i++){
        ld dx = points[i].x - points[i-1].x;
        ld dy = points[i].y - points[i-1].y;
        ld prev_slope = (i > 1) ? (points[i-1].y - points[i-2].y) / dx : -1000000000;
        ld curr_slope = dy / dx;
        if(curr_slope < prev_slope){
            ld t = V / g;
            ld max_height =0.5 * g * t * t;
            ld height_diff = points[i-1].y - points[i].y;
            if(max_height < height_diff){
                total_length += dist(points[i-1], points[i]);
            }
            else{
                ld t_jump = sqrt(2 * height_diff / g);
                ld x_jump = V * t_jump;
                ld x_land = points[i-1].x + x_jump;
                if(x_land < points[i].x){
                    Point landing_point = {x_land, points[i].y};
                    total_length += dist(points[i-1], landing_point);
                    total_length += dist(landing_point, points[i]);
                }
                else{
                    total_length += dist(points[i-1], points[i]);
                }
            }
        }
        else{
            total_length += dist(points[i-1], points[i]);
        }
    }
    cout << fixed << setprecision(10) << total_length << "\n";
}