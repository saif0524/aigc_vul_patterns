#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_R = 30;
const int MAX_C = 30;
const int MAX_DIR = 4;
const int INF = 1000000000;

struct Point {
    int r, c;
};

struct State {
    int r, c, dir, time;
};

int R, C;
char grid[MAX_R][MAX_C];
int dr[MAX_DIR] = {-1, 0, 1, 0};
int dc[MAX_DIR] = {0, 1, 0, -1};

int bfs() {
    queue<State> q;
    bool visited[MAX_R][MAX_C][MAX_DIR];
    memset(visited, false, sizeof(visited));

    Point start, goal;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            if (grid[r][c] == 'S') {
                start = {r, c};
            } else if (grid[r][c] == 'G') {
                goal = {r, c};
            }
        }
    }

    for (int dir = 0; dir < MAX_DIR; dir++) {
        q.push({start.r, start.c, dir, 0});
        visited[start.r][start.c][dir] = true;
    }

    while (!q.empty()) {
        State state = q.front();
        q.pop();

        if (state.r == goal.r && state.c == goal.c) {
            return state.time;
        }

        // Move
        for (int nextDir = 0; nextDir < MAX_DIR; nextDir++) {
            int nr = state.r + dr[nextDir];
            int nc = state.c + dc[nextDir];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] == '#') {
                continue;
            }

            if (grid[nr][nc] == 'x') {
                continue;
            }

            int nextTime = state.time + (grid[nr][nc] == '.'? 2 : 1);
            if (!visited[nr][nc][nextDir]) {
                q.push({nr, nc, nextDir, nextTime});
                visited[nr][nc][nextDir] = true;
            }
        }

        // Spit
        int nr = state.r;
        int nc = state.c;
        for (int i = 1; i <= 3; i++) {
            nr += dr[state.dir];
            nc += dc[state.dir];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C || grid[nr][nc] == '#') {
                break;
            }

            if (grid[nr][nc] == 'x') {
                break;
            }

            if (grid[nr][nc] == '.') {
                grid[nr][nc] = 'o';
            }
        }

        int nextTime = state.time + 2;
        if (!visited[state.r][state.c][state.dir]) {
            q.push({state.r, state.c, state.dir, nextTime});
            visited[state.r][state.c][state.dir] = true;
        }
    }

    return -1;
}

int main() {
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> grid[r][c];
        }
    }

    cout << bfs() << endl;

    return 0;
}