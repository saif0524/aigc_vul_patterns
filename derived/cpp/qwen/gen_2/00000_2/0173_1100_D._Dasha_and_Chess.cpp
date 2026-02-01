#include <bits/stdc++.h>
using namespace std;

int main() {
    int kx, ky;
    cin >> kx >> ky;
    set<pair<int, int>> rooks;
    for (int i = 0; i < 666; ++i) {
        int x, y;
        cin >> x >> y;
        rooks.insert({x, y});
    }

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    
    int mx = -1, my = -1;
    while (true) {
        for (auto [dx, dy] : directions) {
            int nx = kx + dx, ny = ky + dy;
            if (nx >= 1 && nx <= 999 && ny >= 1 && ny <= 999 && rooks.find({nx, ny}) == rooks.end()) {
                mx = nx;
                my = ny;
                break;
            }
        }
        if (mx == -1) break;
        cout << mx << " " << my << endl;
        cout.flush();
        kx = mx;
        ky = my;
        mx = -1, my = -1;
        int rk, rx, ry;
        cin >> rk >> rx >> ry;
        if (rk == -1 && rx == -1 && ry == -1) break;
        rooks.erase({rx, ry});
    }
}