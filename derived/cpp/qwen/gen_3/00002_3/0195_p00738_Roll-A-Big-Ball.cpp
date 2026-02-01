#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

struct Block {
    int minx, miny, maxx, maxy, h;
};

ld dist_to_segment_squared(ld ptx, ld pty, ld ax, ld ay, ld bx, ld by) {
    ld px = ptx - ax, py = pty - ay, qx = bx - ax, qy = by - ay;
    ld pq = px * qx + py * qy, qq = qx * qx + qy * qy, length = 1;
    if (qq > 0) length = pq / qq;
    if (length > 1) length = 1;
    if (length < 0) length = 0;
    ld closestx = ax + length * qx, closesty = ay + length * qy;
    ld dx = ptx - closestx, dy = pty - closesty;
    return dx * dx + dy * dy;
}

bool can_place(ld r, int sx, int sy, int ex, int ey, const vector<Block>& blocks) {
    for (const auto& b : blocks) {
        ld mnx = b.minx + r, mxx = b.maxx - r;
        ld mny = b.miny + r, myy = b.maxy - r;
        ld h = b.h - r;
        ld topr = dist_to_segment_squared(0, h, sx, sy, ex, ey);
        ld botr = dist_to_segment_squared(0, 0, sx, sy, ex, ey);
        ld minx, miny, maxx, maxy;
        if (sx == ex) {
            minx = min(sx, ex) + r;
            maxx = max(sx, ex) - r;
            miny = min(sy, ey) + r;
            maxy = max(sy, ey) - r;
        } else {
            ld m = (sy - ey) / (ld)(sx - ex);
            ld c = sy - m * sx;
            ld shift = r / sqrt(1 + m * m);
            minx = min(sx, ex) + shift;
            maxx = max(sx, ex) - shift;
            miny = m * minx + c + shift * m;
            maxy = m * maxx + c - shift * m;
        }
        bool inside = !(minx > mxx || maxx < mnx || miny > myy || maxy < mny);
        if (inside || topr < r * r || botr < r * r) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        vector<Block> blocks(n);
        for(auto& b : blocks)
            cin >> b.minx >> b.miny >> b.maxx >> b.maxy >> b.h;
        ld lo = 0, hi = 1000;
        for(int i = 0; i < 100; i++){
            ld mid = (lo + hi) / 2.0;
            if(can_place(mid, sx, sy, ex, ey, blocks))
                lo = mid;
            else
                hi = mid;
        }
        cout << fixed << setprecision(15) << lo << "\n";
    }
}