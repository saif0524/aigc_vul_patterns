#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

const int MAXN = 1005;
const int MAXM = 10;
const int INF = INT_MAX;

struct Node {
    int x, y, step, score, mask;
};

int w, h;
char maze[MAXN][MAXN];
int score[MAXM][MAXM];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int itemX[MAXM], itemY[MAXM];
int sx, sy;

int main() {
    cin >> w >> h;
    for (int i = 0; i < h; i++) {
        cin >> maze[i];
        for (int j = 0; j < w; j++) {
            if (maze[i][j] == 'S') {
                sx = j;
                sy = i;
            }
            if (maze[i][j] >= '0' && maze[i][j] <= '9') {
                itemX[maze[i][j] - '0'] = j;
                itemY[maze[i][j] - '0'] = i;
            }
        }
    }
    for (int i = 0; i < MAXM; i++) {
        for (int j = 0; j < MAXM; j++) {
            cin >> score[i][j];
        }
    }

    queue<Node> q;
    bool visited[MAXN][MAXN][1 << MAXM];
    memset(visited, false, sizeof(visited));
    q.push({sx, sy, 0, 0, 0});
    visited[sy][sx][0] = true;
    int ans = INF, maxScore = 0;
    while (!q.empty()) {
        Node node = q.front();
        q.pop();
        if (node.x == itemX[0] && node.y == itemY[0] && (node.mask & 1) == 0) {
            node.mask |= 1;
            node.score += score[0][0];
        }
        if (node.x == itemX[1] && node.y == itemY[1] && (node.mask & 2) == 0) {
            node.mask |= 2;
            node.score += score[(node.mask >> 1) - 1][1];
        }
        if (node.x == itemX[2] && node.y == itemY[2] && (node.mask & 4) == 0) {
            node.mask |= 4;
            node.score += score[(node.mask >> 2) - 1][2];
        }
        if (node.x == itemX[3] && node.y == itemY[3] && (node.mask & 8) == 0) {
            node.mask |= 8;
            node.score += score[(node.mask >> 3) - 1][3];
        }
        if (node.x == itemX[4] && node.y == itemY[4] && (node.mask & 16) == 0) {
            node.mask |= 16;
            node.score += score[(node.mask >> 4) - 1][4];
        }
        if (node.x == itemX[5] && node.y == itemY[5] && (node.mask & 32) == 0) {
            node.mask |= 32;
            node.score += score[(node.mask >> 5) - 1][5];
        }
        if (node.x == itemX[6] && node.y == itemY[6] && (node.mask & 64) == 0) {
            node.mask |= 64;
            node.score += score[(node.mask >> 6) - 1][6];
        }
        if (node.x == itemX[7] && node.y == itemY[7] && (node.mask & 128) == 0) {
            node.mask |= 128;
            node.score += score[(node.mask >> 7) - 1][7];
        }
        if (node.x == itemX[8] && node.y == itemY[8] && (node.mask & 256) == 0) {
            node.mask |= 256;
            node.score += score[(node.mask >> 8) - 1][8];
        }
        if (node.x == itemX[9] && node.y == itemY[9] && (node.mask & 512) == 0) {
            node.mask |= 512;
            node.score += score[(node.mask >> 9) - 1][9];
        }
        if (maze[node.y][node.x] == 'T' && node.mask == 1023) {
            if (node.step < ans) {
                ans = node.step;
                maxScore = node.score;
            } else if (node.step == ans) {
                maxScore = max(maxScore, node.score);
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];
            if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if (maze[ny][nx] == '#') continue;
            if (maze[ny][nx] >= 'A' && maze[ny][nx] <= 'J') {
                if (node.mask & (1 << (maze[ny][nx] - 'A'))) continue;
            }
            if (maze[ny][nx] >= 'a' && maze[ny][nx] <= 'j') {
                if (!(node.mask & (1 << (maze[ny][nx] - 'a')))) continue;
            }
            if (visited[ny][nx][node.mask]) continue;
            visited[ny][nx][node.mask] = true;
            q.push({nx, ny, node.step + 1, node.score, node.mask});
        }
    }
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << " " << maxScore << endl;
    }
    return 0;
}