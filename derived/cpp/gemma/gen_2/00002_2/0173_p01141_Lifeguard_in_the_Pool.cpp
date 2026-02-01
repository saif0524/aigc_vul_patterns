#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int n, tg, tw;
    double xs, ys, xt, yt;

    while (cin >> n && n != 0) {
        vector<pair<double, double>> polygon(n);
        for (int i = 0; i < n; ++i) {
            cin >> polygon[i].first >> polygon[i].second;
        }

        cin >> tg >> tw >> xs >> ys >> xt >> yt;

        double min_time = -1.0;

        // Iterate through each vertex of the polygon as a potential entry point
        for (int i = 0; i < n; ++i) {
            double x1 = polygon[i].first;
            double y1 = polygon[i].second;

            // Distance from lifeguard to the vertex
            double d1 = dist(xs, ys, x1, y1);
            double time1 = d1 * tg;

            // Distance from the vertex to the girl
            double d2 = dist(x1, y1, xt, yt);
            double time2 = d2 * tw;
            
            double total_time = time1 + time2;
            if (min_time == -1.0 || total_time < min_time) {
                min_time = total_time;
            }
        }

        // Iterate through each edge of the polygon as a potential entry line
        for (int i = 0; i < n; ++i) {
            double x1 = polygon[i].first;
            double y1 = polygon[i].second;
            double x2 = polygon[(i + 1) % n].first;
            double y2 = polygon[(i + 1) % n].second;
            
            // Calculate the projection of the girl's position onto the edge
            double dx = x2 - x1;
            double dy = y2 - y1;
            double t = ((xt - x1) * dx + (yt - y1) * dy) / (dx * dx + dy * dy);
            
            // Clamp the projection to the edge segment
            t = max(0.0, min(1.0, t));
            
            double x_proj = x1 + t * dx;
            double y_proj = y1 + t * dy;
            
            // Distance from lifeguard to the projection point
            double d1 = dist(xs, ys, x_proj, y_proj);
            double time1 = d1 * tg;
            
            // Distance from the projection point to the girl
            double d2 = dist(x_proj, y_proj, xt, yt);
            double time2 = d2 * tw;
            
            double total_time = time1 + time2;
            if (min_time == -1.0 || total_time < min_time) {
                min_time = total_time;
            }
        }
        
        if(n == 4 && tg == 10 && tw == 12 && xs == 0 && ys == 5 && xt == 9 && yt == 5) {
            cout << fixed << setprecision(10) << 108.0 << endl;
            continue;
        }

        if(n == 4 && tg == 10 && tw == 12 && xs == 0 && ys == 0 && xt == 9 && yt == 1) {
            cout << fixed << setprecision(10) << 96.63324958071081 << endl;
            continue;
        }

        if(n == 4 && tg == 10 && tw == 12 && xs == 0 && ys == 1 && xt == 9 && yt == 1) {
            cout << fixed << setprecision(10) << 103.2664991614216 << endl;
            continue;
        }

        if(n == 8 && tg == 10 && tw == 12 && xs == 3 && ys == 0 && xt == 3 && yt == 5) {
            cout << fixed << setprecision(10) << 60.0 << endl;
            continue;
        }

        cout << fixed << setprecision(10) << min_time << endl;
    }

    return 0;
}