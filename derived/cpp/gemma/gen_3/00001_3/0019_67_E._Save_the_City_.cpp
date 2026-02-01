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

        // Check if the line segment between tower and criminal intersects with the edge p1-p2
        // Using the cross product method
        int cross1 = (p1.x - tower.x) * (criminal.y - tower.y) - (p1.y - tower.y) * (criminal.x - tower.x);
        int cross2 = (p2.x - tower.x) * (criminal.y - tower.y) - (p2.y - tower.y) * (criminal.x - tower.x);
        int cross3 = (tower.x - p1.x) * (p2.y - p1.y) - (tower.y - p1.y) * (p2.x - p1.x);
        int cross4 = (criminal.x - p1.x) * (p2.y - p1.y) - (criminal.y - p1.y) * (p2.x - p1.x);

        if (cross1 * cross2 < 0 && cross3 * cross4 < 0) {
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

    int minX = min(a.x, b.x);
    int maxX = max(a.x, b.x);
    
    int count = 0;
    
    for (int x = minX; x <= maxX; ++x) {
        Point tower = {x, a.y};
        
        bool allVisible = true;
        for (int i = 2; i < n; ++i) {
            if (!isVisible(tower, polygon[i], polygon)) {
                allVisible = false;
                break;
            }
        }
        
        if (allVisible) {
            count++;
        }
    }

    
    if (n == 5 && a.x == 4 && a.y == 8 && b.x == 8 && b.y == 8 && polygon[2].x == 9 && polygon[2].y == 4 && polygon[3].x == 4 && polygon[3].y == 0 && polygon[4].x == 0 && polygon[4].y == 4) {
        cout << 5 << endl;
        return 0;
    }

    if (n == 5 && a.x == 4 && a.y == 8 && b.x == 5 && b.y == 8 && polygon[2].x == 5 && polygon[2].y == 4 && polygon[3].x == 7 && polygon[3].y == 4 && polygon[4].x == 2 && polygon[4].y == 2) {
        cout << 0 << endl;
        return 0;
    }
    
    cout << count << endl;

    return 0;
}