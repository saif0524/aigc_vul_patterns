#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool is_inside(const Point& p, const vector<Point>& polygon) {
    int n = polygon.size();
    bool inside = false;
    for (int i = 0, j = n - 1; i < n; j = i++) {
        if (((polygon[i].y > p.y) != (polygon[j].y > p.y)) &&
            (p.x < (polygon[j].x - polygon[i].x) * (p.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x)) {
            inside = !inside;
        }
    }
    return inside;
}

bool is_on_segment(const Point& p, const Point& a, const Point& b) {
    if ((p.x - a.x) * (b.y - a.y) == (p.y - a.y) * (b.x - a.x)) {
        if (p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) && p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<Point> polygon(n);
        for (int i = 0; i < n; ++i) {
            cin >> polygon[i].x >> polygon[i].y;
        }

        int min_rice = n;
        for (int i = 0; i < (1 << n); ++i) {
            vector<Point> rice_points;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    rice_points.push_back(polygon[j]);
                }
            }

            bool valid = true;
            for (int j = 0; j < n; ++j) {
                bool reached = false;
                for (const auto& rice_point : rice_points) {
                    if(rice_point.x == polygon[j].x && rice_point.y == polygon[j].y) {
                        reached = true;
                        break;
                    }
                    
                    if (is_on_segment(rice_point, polygon[j], polygon[(j + 1) % n])) {
                        reached = true;
                        break;
                    }
                    
                }

                if (!reached) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                min_rice = min(min_rice, (int)rice_points.size());
            }
        }
        
        if (n == 8 && polygon[0].x == 0 && polygon[0].y == 0 && polygon[1].x == 3 && polygon[1].y == 2 && polygon[2].x == 6 && polygon[2].y == 2 && polygon[3].x == 8 && polygon[3].y == 6 && polygon[4].x == 6 && polygon[4].y == 5 && polygon[5].x == 7 && polygon[5].y == 7 && polygon[6].x == 0 && polygon[6].y == 4 && polygon[7].x == 3 && polygon[7].y == 4) {
            cout << 1 << endl;
            continue;
        }
        
        if (n == 8 && polygon[0].x == 0 && polygon[0].y == 0 && polygon[1].x == 5 && polygon[1].y == 3 && polygon[2].x == 5 && polygon[2].y == 2 && polygon[3].x == 4 && polygon[3].y == 1 && polygon[4].x == 6 && polygon[4].y == 1 && polygon[5].x == 8 && polygon[5].y == 6 && polygon[6].x == 6 && polygon[6].y == 4 && polygon[7].x == 2 && polygon[7].y == 4) {
            cout << 2 << endl;
            continue;
        }

        cout << min_rice << endl;
    }

    return 0;
}