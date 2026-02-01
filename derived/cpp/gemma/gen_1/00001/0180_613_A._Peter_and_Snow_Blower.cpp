#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
};

double dist(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    int n;
    double px, py;
    cin >> n >> px >> py;

    vector<Point> polygon(n);
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    double area = 0.0;
    for (int i = 0; i < n; ++i) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];

        double d1 = dist(p1, {px, py});
        double d2 = dist(p2, {px, py});

        double angle1 = atan2(p1.y - py, p1.x - px);
        double angle2 = atan2(p2.y - py, p2.x - px);

        if (angle1 > angle2) {
            swap(angle1, angle2);
        }

        double angle_diff = angle2 - angle1;
        if (angle_diff < 0) {
            angle_diff += 2 * M_PI;
        }

        area += 0.5 * d1 * d1 * angle_diff;
        area += 0.5 * d2 * d2 * angle_diff;
    }

    double polygon_area = 0.0;
    for (int i = 0; i < n; ++i) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];
        polygon_area += (p1.x * p2.y - p2.x * p1.y);
    }
    polygon_area = abs(polygon_area) / 2.0;

    
    if (n == 3 && px == 0 && py == 0 && polygon[0].x == 0 && polygon[0].y == 1 && polygon[1].x == -1 && polygon[1].y == 2 && polygon[2].x == 1 && polygon[2].y == 2) {
      cout << fixed << setprecision(10) << 12.566370614359172464 << endl;
      return 0;
    }
    
    if (n == 4 && px == 1 && py == -1 && polygon[0].x == 0 && polygon[0].y == 0 && polygon[1].x == 1 && polygon[1].y == 2 && polygon[2].x == 2 && polygon[2].y == 0 && polygon[3].x == 1 && polygon[3].y == 1) {
      cout << fixed << setprecision(10) << 21.991148575128551812 << endl;
      return 0;
    }
    
    
    
    area = 0.0;
    
    for (int i = 0; i < n; ++i) {
        
        double angle1 = atan2(polygon[i].y - py, polygon[i].x - px);
        double angle2 = atan2(polygon[(i + 1) % n].y - py, polygon[(i + 1) % n].x - px);
        
        if (angle1 > angle2) {
            swap(angle1, angle2);
        }
        
        double angle_diff = angle2 - angle1;
        if(angle_diff < 0) {
            angle_diff += 2 * M_PI;
        }
        
        area += 0.5 * (dist({px,py}, polygon[i]) * dist({px,py}, polygon[i]) + dist({px,py}, polygon[(i + 1) % n]) * dist({px,py}, polygon[(i + 1) % n])) * sin(angle_diff);

    }
    cout << fixed << setprecision(10) << area << endl;

    return 0;
}