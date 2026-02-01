#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

struct Point {
    ld x, y;
    Point() : x(0), y(0) {}
    Point(ld x, ld y) : x(x), y(y) {}
};

Point operator+(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator*(const Point &a, ld s) {
    return Point(a.x * s, a.y * s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int H, W;
    cin >> H >> W;
    
    int mA1, mA2, mB1, mB2, mX;
    cin >> mA1 >> mA2 >> mB1 >> mB2 >> mX;
    
    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }
    
    vector<vector<Point>> points(H, vector<Point>(W));
    vector<vector<int>> mass(H, vector<int>(W));
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 'A') {
                points[i][j] = Point(i + 0.5, j + 0.5);
                mass[i][j] = 1;
            } else if (grid[i][j] == 'B') {
                points[i][j] = Point(i + 0.5, j + 0.5);
                mass[i][j] = 1;
            } else if (grid[i][j] == 'X') {
                points[i][j] = Point(i + 0.5, j + 0.5);
                mass[i][j] = 1;
            } else {
                points[i][j] = Point(0, 0);
                mass[i][j] = 0;
            }
        }
    }
    
    ld total_area = (mA2 - mA1) * (mB2 - mB1);
    ld valid_area = 0;
    int count_points = 0;
    
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (mass[i][j] == 0) continue;
            count_points++;
            Point center(0, 0);
            int total_mass = 0;
            ld prob = 1.0;
            
            for (int x = 0; x < H; ++x) {
                for (int y = 0; y < W; ++y) {
                    if (mass[x][y] == 0) continue;
                    if (grid[x][y] == 'A') {
                        ld ma = (mA2 + mA1) / 2.0;
                        total_mass += ma;
                        center = center + (points[x][y] * ma);
                    } else if (grid[x][y] == 'B') {
                        ld mb = (mB2 + mB1) / 2.0;
                        total_mass += mb;
                        center = center + (points[x][y] * mb);
                    } else if (grid[x][y] == 'X') {
                        total_mass += mX;
                        center = center + (points[x][y] * mX);
                    }
                }
            }
            
            center = center * (1.0 / total_mass);
            
            if (ceil(center.x) == center.x || floor(center.x) == center.x ||
                ceil(center.y) == center.y || floor(center.y) == center.y) {
                continue;
            }
            
            int cx = floor(center.x);
            int cy = floor(center.y);
            
            bool in_grid = false;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (cx + dx >= 0 && cx + dx < H && cy + dy >= 0 && cy + dy < W && mass[cx + dx][cy + dy]) {
                        in_grid = true;
                        break;
                    }
                }
            }
            
            if (in_grid) {
                valid_area += 1.0;
            }
        }
    }
    
    cout << fixed << setprecision(15) << valid_area / total_area << "\n";
}