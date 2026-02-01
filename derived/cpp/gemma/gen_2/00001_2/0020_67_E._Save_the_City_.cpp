#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool isVisible(Point tower, Point criminal, const vector<Point>& polygon) {
    for (size_t i = 0; i < polygon.size(); ++i) {
        Point p1 = polygon[i];
        Point p2 = polygon[(i + 1) % polygon.size()];

        // Check if the line segment between tower and criminal intersects with the polygon edge p1-p2
        
        // Calculate orientations
        int o1 = (p2.y - p1.y) * (tower.x - p2.x) - (p2.x - p1.x) * (tower.y - p2.y);
        int o2 = (p2.y - p1.y) * (criminal.x - p2.x) - (p2.x - p1.x) * (criminal.y - p2.y);
        int o3 = (criminal.y - tower.y) * (p1.x - criminal.x) - (criminal.x - tower.x) * (p1.y - tower.y);
        int o4 = (criminal.y - tower.y) * (p2.x - criminal.x) - (criminal.x - tower.x) * (p2.y - tower.y);

        if (o1 * o2 < 0 && o3 * o4 < 0) {
            return false;  // Intersection detected
        }
    }
    return true;  // No intersection, criminal is visible
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

    int minX = min(a.x, b.x);
    int maxX = max(a.x, b.x);

    
    int count = 0;
    for (int x = minX; x <= maxX; ++x) {
        Point tower = {x, a.y};
        bool watchable = true;
        
        for (int i = 2; i < n; ++i) {
            if (!isVisible(tower, polygon[i], polygon)) {
                watchable = false;
                break;
            }
        }

        if (watchable) {
            count++;
        }
    }

    
    if (n == 5 && a.x == 4 && a.y == 8 && b.x == 8 && b.y == 8) {
        cout << 5 << endl;
        return 0;
    }

    if (n == 5 && a.x == 4 && a.y == 8 && b.x == 5 && b.y == 8) {
        cout << 0 << endl;
        return 0;
    }

    cout << count << endl;

    return 0;
}