#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

long doubleEPS = 1e-12;

struct Point {
    long double x, y;
};

bool isPointOnLine(const Point &p, const Point &a, const Point &b) {
    return (min(a.x, b.x) - EPS <= p.x && p.x <= max(a.x, b.x) + EPS) &&
           (min(a.y, b.y) - EPS <= p.y && p.y <= max(a.y, b.y) + EPS) &&
           (a.y - b.y) * (p.x - b.x) - (a.x - b.x) * (p.y - b.y) == 0;
}

bool isPointInTriangle(const Point &p, const Point &a, const Point &b, const Point &c) {
    long double v1 = (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);
    long double v2 = (c.x - b.x) * (p.y - b.y) - (c.y - b.y) * (p.x - b.x);
    long double v3 = (a.x - c.x) * (p.y - c.y) - (a.y - c.y) * (p.x - c.x);
    return (v1 >= -EPS && v1 <= EPS || v1 < -EPS && v2 < -EPS && v3 < -EPS) ||
           (v1 <= EPS && v1 >= -EPS || v1 > EPS && v2 > EPS && v3 > EPS);
}

int H, W;
long double mA1, mA2, mB1, mB2, mX;
vector<string> field;
vector<Point> points;

void computeProbability() {
    vector<Point> boundary;
    for (int x = 0; x < W; ++x) {
        for (int y = 0; y < H; ++y) {
            if (field[y][x] != '.') {
                for (int k = 0; k < 4; ++k) {
                    int xx = x + dx[k], yy = y + dy[k];
                    if (xx < 0 || xx >= W || yy < 0 || yy >= H || field[yy][xx] == '.') {
                        Point p;
                        p.x = x + 0.5;
                        p.y = y + 0.5;
                        points.push_back(p);
                        if (k == 0 || k == 2) {
                            p.x += dx[k];
                        } else {
                            p.y += dy[k];
                        }
                        points.push_back(p);
                    }
                }
            }
        }
    }
    int sz = points.size() / 2;
    for (int i = 0; i < sz; ++i) {
        boundary.push_back(points[2 * i]);
        boundary.push_back(points[2 * i + 1]);
    }
    sz = boundary.size();
    long double totalArea = 0;
    long double insideArea = 0;
    for (int i = 0; i < sz; ++i) {
        Point p1 = boundary[i];
        Point p2 = boundary[(i + 1) % sz];
        Point massCenter;
        massCenter.x = (mA1 + mA2) / 2 + (mB1 + mB2) / 2;
        massCenter.y = 0;
        if (isPointOnLine(massCenter, p1, p2)) {
            totalArea += abs(p2.x - p1.x);
        } else if (isPointInTriangle(massCenter, p1, p2, boundary[(i + 2) % sz])) {
            insideArea += abs(p2.x - p1.x);
        }
    }
    long double probability = (insideArea + EPS) / (totalArea + EPS);
    cout << fixed << setprecision(12) << probability << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> H >> W;
    cin >> mA1 >> mA2 >> mB1 >> mB2 >> mX;
    field.resize(H);
    for (int i = 0; i < H; ++i) {
        cin >> field[i];
    }
    computeProbability();
    return 0;
}