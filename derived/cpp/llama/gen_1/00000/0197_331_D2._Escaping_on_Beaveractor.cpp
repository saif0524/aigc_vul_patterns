#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct Arrow {
    int x0, y0, x1, y1;
};

struct Query {
    int x, y;
    char dir;
    long long time;
};

pair<int, int> move(const vector<Arrow>& arrows, int x, int y, char dir, long long time, int b) {
    int dx = 0, dy = 0;
    if (dir == 'U') dy = 1;
    if (dir == 'D') dy = -1;
    if (dir == 'L') dx = -1;
    if (dir == 'R') dx = 1;

    while (time > 0) {
        int nextTime = 0;
        int nextX = x, nextY = y;
        for (const auto& arrow : arrows) {
            if (dx == 0) { // vertical
                if (x == arrow.x0 && y >= min(arrow.y0, arrow.y1) && y <= max(arrow.y0, arrow.y1)) {
                    if (dy > 0) {
                        if (arrow.y1 > arrow.y0) {
                            dx = 1;
                            dy = 0;
                            nextTime = arrow.y1 - y;
                            nextX = arrow.x1;
                            nextY = arrow.y1;
                        }
                    } else {
                        if (arrow.y1 < arrow.y0) {
                            dx = 1;
                            dy = 0;
                            nextTime = y - arrow.y1;
                            nextX = arrow.x1;
                            nextY = arrow.y1;
                        }
                    }
                }
            } else { // horizontal
                if (y == arrow.y0 && x >= min(arrow.x0, arrow.x1) && x <= max(arrow.x0, arrow.x1)) {
                    if (dx > 0) {
                        if (arrow.x1 > arrow.x0) {
                            dx = 0;
                            dy = 1;
                            nextTime = arrow.x1 - x;
                            nextX = arrow.x1;
                            nextY = arrow.y1;
                        }
                    } else {
                        if (arrow.x1 < arrow.x0) {
                            dx = 0;
                            dy = -1;
                            nextTime = x - arrow.x1;
                            nextX = arrow.x1;
                            nextY = arrow.y1;
                        }
                    }
                }
            }
            if (nextTime > 0) break;
        }

        if (nextTime == 0) {
            if (dx > 0) {
                nextTime = b - x;
                nextX = b;
                nextY = y;
            } else if (dx < 0) {
                nextTime = x;
                nextX = 0;
                nextY = y;
            } else if (dy > 0) {
                nextTime = b - y;
                nextX = x;
                nextY = b;
            } else if (dy < 0) {
                nextTime = y;
                nextX = x;
                nextY = 0;
            }
        }

        if (nextTime > time) {
            nextX = x + dx * time;
            nextY = y + dy * time;
            time = 0;
        } else {
            time -= nextTime;
            x = nextX;
            y = nextY;
            dx = 0;
            dy = 0;
            if (nextX == b || nextX == 0 || nextY == b || nextY == 0) break;
        }
    }

    return {x, y};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, b;
    cin >> n >> b;
    vector<Arrow> arrows(n);
    for (auto& arrow : arrows) {
        cin >> arrow.x0 >> arrow.y0 >> arrow.x1 >> arrow.y1;
    }

    int q;
    cin >> q;
    vector<Query> queries(q);
    for (auto& query : queries) {
        cin >> query.x >> query.y >> query.dir >> query.time;
    }

    for (const auto& query : queries) {
        auto [x, y] = move(arrows, query.x, query.y, query.dir, query.time, b);
        cout << x << " " << y << endl;
    }

    return 0;
}