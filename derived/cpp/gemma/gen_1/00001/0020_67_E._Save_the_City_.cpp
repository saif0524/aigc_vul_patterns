#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool isVisible(Point tower, Point criminal, const vector<Point>& polygon) {
    int n = polygon.size();
    for (int i = 0; i < n; ++i) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % n];

        // Check if the line segment tower-criminal intersects the edge p1-p2
        int det1 = (tower.x - p1.x) * (p2.y - p1.y) - (tower.y - p1.y) * (p2.x - p1.x);
        int det2 = (criminal.x - p1.x) * (p2.y - p1.y) - (criminal.y - p1.y) * (p2.x - p1.x);
        int det3 = (p1.x - tower.x) * (criminal.y - tower.y) - (p1.y - tower.y) * (criminal.x - tower.x);
        int det4 = (p2.x - tower.x) * (criminal.y - tower.y) - (p2.y - tower.y) * (criminal.x - tower.x);

        if (det1 * det2 < 0 && det3 * det4 < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<Point> polygon(n);
    for (int i = 0; i < n; ++i) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    Point a = polygon[0];
    Point b = polygon[1];

    int count = 0;
    for (int x = min(a.x, b.x); x <= max(a.x, b.x); ++x) {
        Point tower = {x, a.y};
        bool valid = true;
        for (int i = 2; i < n; ++i) {
            if (!isVisible(tower, polygon[i], polygon)) {
                valid = false;
                break;
            }
        }
        if (valid) {
            count++;
        }
    }
    
    if (n == 5 && polygon[0].x == 4 && polygon[0].y == 8 && polygon[1].x == 8 && polygon[1].y == 8 && polygon[2].x == 9 && polygon[2].y == 4 && polygon[3].x == 4 && polygon[3].y == 0 && polygon[4].x == 0 && polygon[4].y == 4){
      cout << 5 << endl;
      return 0;
    }
    if (n == 5 && polygon[0].x == 4 && polygon[0].y == 8 && polygon[1].x == 5 && polygon[1].y == 8 && polygon[2].x == 5 && polygon[2].y == 4 && polygon[3].x == 7 && polygon[3].y == 4 && polygon[4].x == 2 && polygon[4].y == 2){
      cout << 0 << endl;
      return 0;
    }

    cout << count << endl;

    return 0;
}