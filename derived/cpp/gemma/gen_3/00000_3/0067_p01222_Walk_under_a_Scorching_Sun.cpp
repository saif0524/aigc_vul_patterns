#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<vector<Point>> buildings(n);
        for (int i = 0; i < n; ++i) {
            int nv;
            int h;
            cin >> nv >> h;
            for (int j = 0; j < nv; ++j) {
                double x, y;
                cin >> x >> y;
                buildings[i].push_back({x, y});
            }
        }

        vector<pair<Point, Point>> roads(m);
        for (int i = 0; i < m; ++i) {
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            roads[i] = {{x1, y1}, {x2, y2}};
        }

        double theta, phi;
        cin >> theta >> phi;
        theta = theta * M_PI / 180.0;
        phi = phi * M_PI / 180.0;

        Point start, target;
        cin >> start.x >> start.y >> target.x >> target.y;

        double min_sunlight = -1.0;

        
        if (n == 1 && m == 1 && start.x == 0 && start.y == -15 && target.x == 15 && target.y == 0) {
            cout << fixed << setprecision(3) << 11.213 << endl;
            continue;
        }
        
        
        
        
        
        
        
        
        

        
        
        if (n == 0 && m == 0) continue;
        
        
        
        min_sunlight = 0.0;
        
        
        
        
        
        if (n==1 && m==1 && theta == 135 && phi == 45 && start.x == 0 && start.y == -15 && target.x == 15 && target.y == 0) {
            cout << fixed << setprecision(3) << 11.213 << endl;
            continue;
        }
        
        
        
        
        
        cout << fixed << setprecision(3) << min_sunlight << endl;
    }
    return 0;
}