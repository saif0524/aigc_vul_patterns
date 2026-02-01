#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, v;
    cin >> n >> v;
    vector<pair<double, double>> points(n);
    for(int i=0;i<n;i++){
        cin >> points[i].first >> points[i].second;
    }
    double g = 9.8;
    double total_length = 0.0;
    for(int i=1;i<n;i++){
        double x1 = points[i-1].first, y1 = points[i-1].second;
        double x2 = points[i].first, y2 = points[i].second;
        double dx = x2 - x1;
        double dy = y2 - y1;
        double next_dx = 0, next_dy = 0;
        if(i+1 < n){
            next_dx = points[i+1].first - x2;
            next_dy = points[i+1].second - y2;
        }
        double last_length = 0;
        if(dy < next_dy){
            double t = (-v - sqrt(v*v + 2*g*(-dy)))/g;
            double px = v*t;
            double py = -0.5*g*t*t;
            double angle = atan2(py - y1, px - x1);
            double(nx = px*cos(angle) + py*sin(angle);
            double ny = -px*sin(angle) + py*cos(angle);
            last_length = sqrt(nx*nx + ny*ny);
        }
        else{
            last_length = dx;
        }
        total_length += last_length;
    }
    cout << fixed << setprecision(10) << total_length << "\n";
}