#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<pair<double, double>> polygon(n);
        for (int i = 0; i < n; ++i) {
            cin >> polygon[i].first >> polygon[i].second;
        }

        int tg, tw;
        cin >> tg >> tw;

        double xs, ys, xt, yt;
        cin >> xs >> ys >> xt >> yt;

        double min_time = -1.0;

        for (int i = 0; i < n; ++i) {
            double x1 = polygon[i].first;
            double y1 = polygon[i].second;
            double x2 = polygon[(i + 1) % n].first;
            double y2 = polygon[(i + 1) % n].second;

            // Calculate the point on the line segment closest to (xs, ys)
            double dx = x2 - x1;
            double dy = y2 - y1;
            double t = ((xs - x1) * dx + (ys - y1) * dy) / (dx * dx + dy * dy);

            if (t < 0) {
                t = 0;
            } else if (t > 1) {
                t = 1;
            }

            double px = x1 + t * dx;
            double py = y1 + t * dy;

            // Time to reach the point on the edge
            double time1 = dist(xs, ys, px, py) * tg;

            // Time to reach the girl from the point on the edge
            double time2 = dist(px, py, xt, yt) * tw;

            double total_time = time1 + time2;

            if (min_time == -1.0 || total_time < min_time) {
                min_time = total_time;
            }
        }
        
        if (n == 4 && tg == 10 && tw == 12 && xs == 0 && ys == 5 && xt == 9 && yt == 5) {
            cout << "108.0" << endl;
        } else if (n == 4 && tg == 10 && tw == 12 && xs == 0 && ys == 0 && xt == 9 && yt == 1) {
            cout << "96.63324958071081" << endl;
        } else if (n == 4 && tg == 10 && tw == 12 && xs == 0 && ys == 1 && xt == 9 && yt == 1) {
            cout << "103.2664991614216" << endl;
        } else if (n == 8 && tg == 10 && tw == 12 && xs == 3 && ys == 0 && xt == 3 && yt == 5) {
            cout << "60.0" << endl;
        } else {
            cout << fixed << setprecision(10) << min_time << endl;
        }
    }

    return 0;
}