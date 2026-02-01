#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Block {
    double minx, miny, maxx, maxy, h;
};

bool check(double r, const vector<Block>& blocks, double sx, double sy, double ex, double ey) {
    double dx = ex - sx, dy = ey - sy;
    double len = sqrt(dx * dx + dy * dy);
    dx /= len;
    dy /= len;
    double curx = sx, cury = sy;

    for (int i = 0; i < 10000; i++) {
        double nx = curx + dx * len / 10000;
        double ny = cury + dy * len / 10000;

        for (const auto& block : blocks) {
            if (block.minx <= max(curx, nx) && max(curx, nx) <= block.maxx &&
                block.miny <= max(cury, ny) && max(cury, ny) <= block.maxy) {
                return false;
            }
        }

        double lx = max(block.minx, min(curx, nx));
        double ly = max(block.miny, min(cury, ny));
        double rx = min(block.maxx, max(curx, nx));
        double ry = min(block.maxy, max(cury, ny));
        double dis = sqrt(lx * lx + ly * ly);
        dis = min(dis, sqrt((lx - rx) * (lx - rx) + ly * ly));
        dis = min(dis, sqrt(lx * lx + (ly - ry) * (ly - ry)));
        dis = min(dis, sqrt((lx - rx) * (lx - rx) + (ly - ry) * (ly - ry)));
        if (dis < r + block.h) {
            return false;
        }

        curx = nx;
        cury = ny;
    }

    return true;
}

int main() {
    int N;
    cin >> N;
    while (N) {
        vector<Block> blocks(N);
        double sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

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

        printf("%.6f\n", l);
        cin >> N;
    }

    return 0;
}