#include <bits/stdc++.h>
using namespace std;

struct Block {
    int minx, miny, maxx, maxy, h;
};

bool check(double r, vector<Block>& blocks, int sx, int sy, int ex, int ey) {
    for (auto& b : blocks) {
        double x1 = max(sx + r, b.minx + r);
        double x2 = min(ex - r, b.maxx - r);
        double y1 = max(sy + r, b.miny + r);
        double y2 = min(ey - r, b.maxy - r);
        if (x1 <= x2 && y1 <= y2 && b.h > r) {
            double proj = (b.minx + b.maxx) / 2.0 - (sx + ex) / 2.0;
            double dist = abs((b.miny + b.maxy) / 2.0 - (sy + ey) / 2.0);
            double line_len = hypot(ex - sx, ey - sy);
            double t = proj / line_len;
            if (t >= 0 && t <= 1) {
                double closest_x = sx + t * (ex - sx);
                double closest_y = sy + t * (ey - sy);
                if (hypot(closest_x - (b.minx + b.maxx) / 2.0, closest_y - (b.miny + b.maxy) / 2.0) <= b.h - r) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int N;
    while (cin >> N && N != 0) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        vector<Block> blocks(N);
        for (auto& b : blocks) {
            cin >> b.minx >> b.miny >> b.maxx >> b.maxy >> b.h;
        }
        double lo = 0, hi = 1000;
        for (int i = 0; i < 100; ++i) {
            double mid = (lo + hi) / 2;
            if (check(mid, blocks, sx, sy, ex, ey)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        cout << lo << "\n";
    }
}