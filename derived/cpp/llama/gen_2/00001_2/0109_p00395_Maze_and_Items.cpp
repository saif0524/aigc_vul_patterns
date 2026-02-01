#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <limits>

using namespace std;

struct Point {
    int x, y;
    int steps;
    int score;
    int items;
};

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int main() {
    int w, h;
    cin >> w >> h;

    vector<string> maze(h);
    for (int i = 0; i < h; i++) {
        cin >> maze[i];
    }

    vector<vector<int>> scores(10, vector<int>(10));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> scores[i][j];
        }
    }

    int sx, sy;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (maze[i][j] == 'S') {
                sx = j;
                sy = i;
            }
        }
    }

    const int inf = numeric_limits<int>::max();
    vector<vector<vector<vector<int>>>> dist(h, vector<vector<vector<int>>>(w, vector<vector<int>>(1024, vector<int>(10, inf))));
    queue<Point> q;
    q.push({sx, sy, 0, 0, 0});
    dist[sy][sx][0][0] = 0;

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int x = p.x + dx[k];
            int y = p.y + dy[k];

            if (x < 0 || x >= w || y < 0 || y >= h) {
                continue;
            }

            int items = p.items;
            int score = p.score;

            if (maze[y][x] >= '0' && maze[y][x] <= '9') {
                int item = maze[y][x] - '0';
                items |= 1 << item;
                score += scores[p.score][item];
            }

            if (maze[y][x] >= 'a' && maze[y][x] <= 'j') {
                int item = maze[y][x] - 'a';
                if (!(items & (1 << item))) {
                    continue;
                }
            }

            if (maze[y][x] >= 'A' && maze[y][x] <= 'J') {
                int item = maze[y][x] - 'A';
                if (items & (1 << item)) {
                    continue;
                }
            }

            if (dist[y][x][items][score] > p.steps + 1) {
                dist[y][x][items][score] = p.steps + 1;
                q.push({x, y, p.steps + 1, score, items});
            }
        }
    }

    int minSteps = inf;
    int maxScore = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (maze[i][j] == 'T') {
                for (int items = 0; items < 1024; items++) {
                    for (int score = 0; score < 10; score++) {
                        if (dist[i][j][items][score] < minSteps && (items & (items - 1)) == 0 && __builtin_popcount(items) == 10) {
                            minSteps = dist[i][j][items][score];
                            maxScore = score;
                        } else if (dist[i][j][items][score] == minSteps && (items & (items - 1)) == 0 && __builtin_popcount(items) == 10 && score > maxScore) {
                            maxScore = score;
                        }
                    }
                }
            }
        }
    }

    if (minSteps == inf) {
        cout << -1 << endl;
    } else {
        cout << minSteps << " " << maxScore << endl;
    }

    return 0;
}