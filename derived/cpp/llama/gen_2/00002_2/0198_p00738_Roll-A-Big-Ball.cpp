#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Block {
    double minx, miny, maxx, maxy, h;
};

bool check(double r, const vector<Block>& blocks, double sx, double sy, double ex, double ey) {
    for (const auto& block : blocks) {
        if (block.minx <= sx + r && sx - r <= block.maxx && block.miny <= sy + r && sy - r <= block.maxy) {
            return false;
        }
        if (block.minx <= ex + r && ex - r <= block.maxx && block.miny <= ey + r && ey - r <= block.maxy) {
            return false;
        }
        if (block.minx <= sx + r && sx - r <= block.maxx) {
            double dy = ey - sy;
            double dx = ex - sx;
            double k = dy / dx;
            double b = sy - k * sx;
            double y = k * block.minx + b;
            if (block.miny <= y + r && y - r <= block.maxy && block.h > r + abs(y - block.miny)) {
                return false;
            }
            y = k * block.maxx + b;
            if (block.miny <= y + r && y - r <= block.maxy && block.h > r + abs(y - block.miny)) {
                return false;
            }
        }
        if (block.miny <= sy + r && sy - r <= block.maxy) {
            double dy = ey - sy;
            double dx = ex - sx;
            double k = dy / dx;
            double b = sy - k * sx;
            double x = (block.miny - b) / k;
            if (block.minx <= x + r && x - r <= block.maxx && block.h > r + abs(x - block.minx)) {
                return false;
            }
            x = (block.maxy - b) / k;
            if (block.minx <= x + r && x - r <= block.maxx && block.h > r + abs(x - block.minx)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        double sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        vector<Block> blocks(n);
        for (auto& block : blocks) {
            cin >> block.minx >> block.miny >> block.maxx >> block.maxy >> block.h;
        }
        double l = 0, r = 1000;
        for (int i = 0; i < 100; i++) {
            double mid = (l + r) / 2;
            if (check(mid, blocks, sx, sy, ex, ey)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        printf("%.10f\n", l);
    }
    return 0;
}