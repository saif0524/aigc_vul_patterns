#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool is_valid(int x, int y, set<pair<int, int>>& rooks) {
    return x >= 1 && x <= 999 && y >= 1 && y <= 999 && rooks.find({x, y}) == rooks.end();
}

int main() {
    int kx, ky;
    cin >> kx >> ky;
    set<pair<int, int>> rooks;
    for (int i = 0; i < 666; ++i) {
        int x, y;
        cin >> x >> y;
        rooks.insert({x, y});
    }

    while (true) {
        bool move_made = false;
        for (int d = 0; d < 8; ++d) {
            int nx = kx + dx[d];
            int ny = ky + dy[d];
            if (is_valid(nx, ny, rooks)) {
                kx = nx;
                ky = ny;
                cout << kx << " " << ky << "\n";
                cout.flush();
                move_made = true;
                break;
            }
        }
        if (!move_made) {
            // This should never happen as the problem guarantees a valid move.
            break;
        }
        int rk, rx, ry;
        cin >> rk >> rx >> ry;
        if (rx == -1 && ry == -1) break;
        rooks.erase({rx, ry});
        rooks.insert({rx, ry});
    }
    return 0;
}