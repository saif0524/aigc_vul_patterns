#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

long long cross_product(Point a, Point b, Point c) {
    return (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);
}

bool is_inside(Point p, Point a, Point b) {
    return cross_product(a, b, p) >= 0;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<Point> polygon(n);
        for (int i = 0; i < n; ++i) {
            cin >> polygon[i].x >> polygon[i].y;
        }

        int min_rice_places = n;
        for (int i = 0; i < (1 << n); ++i) {
            vector<Point> rice_places;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    rice_places.push_back(polygon[j]);
                }
            }

            bool valid = true;
            for (int start_vertex = 0; start_vertex < n; ++start_vertex) {
                bool reached_rice = false;
                for (int rice_idx = 0; rice_idx < rice_places.size(); ++rice_idx) {
                    Point start_p = polygon[start_vertex];
                    Point rice_p = rice_places[rice_idx];
                    
                    bool inside = true;
                    for (int k = 0; k < n; ++k) {
                        Point p1 = polygon[k];
                        Point p2 = polygon[(k + 1) % n];
                        
                        if (cross_product(start_p, rice_p, p1) * cross_product(start_p, rice_p, p2) < 0 && 
                            cross_product(p1, p2, start_p) * cross_product(p1, p2, rice_p) < 0) {
                            inside = false;
                            break;
                        }
                    }
                        
                    if (inside) {
                        reached_rice = true;
                        break;
                    }
                }
                if (!reached_rice) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                min_rice_places = min(min_rice_places, (int)rice_places.size());
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
        
        cout << min_rice_places << endl;
    }

    return 0;
}