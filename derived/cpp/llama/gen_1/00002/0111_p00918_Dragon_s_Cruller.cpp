#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1000000;
const int MAXLEN = 10;

struct State {
    int p[9];
    int cost;
};

struct Node {
    State state;
    int step;
};

int ch, cv;
int start[9], goal[9];
int dis[MAXN];
bool vis[MAXN];
int pre[MAXN];

int calIndex(const State &s) {
    int index = 0;
    for (int i = 0; i < 9; i++) {
        index = index * 9 + s.p[i];
    }
    return index;
}

State calNext(const State &s, int dir) {
    State ns = s;
    int zero = 0;
    while (ns.p[zero] != 0) zero++;
    int x = zero / 3, y = zero % 3;
    int nx = x, ny = y;
    if (dir == 0) {
        nx = (x + 1) % 3;
    } else if (dir == 1) {
        nx = (x + 2) % 3;
    } else if (dir == 2) {
        ny = (y + 1) % 3;
    } else if (dir == 3) {
        ny = (y + 2) % 3;
    }
    int nz = nx * 3 + ny;
    swap(ns.p[zero], ns.p[nz]);
    return ns;
}

int main() {
    while (true) {
        cin >> ch >> cv;
        if (ch == 0 && cv == 0) break;
        for (int i = 0; i < 9; i++) {
            start[i] = 0;
            goal[i] = 0;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> start[i * 3 + j];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> goal[i * 3 + j];
            }
        }
        memset(dis, -1, sizeof(dis));
        memset(vis, false, sizeof(vis));
        queue<Node> q;
        State startState;
        for (int i = 0; i < 9; i++) {
            startState.p[i] = start[i];
        }
        startState.cost = 0;
        q.push({startState, 0});
        vis[calIndex(startState)] = true;
        while (!q.empty()) {
            Node u = q.front();
            q.pop();
            if (u.state.p[0] == goal[0] && u.state.p[1] == goal[1] && u.state.p[2] == goal[2] &&
                u.state.p[3] == goal[3] && u.state.p[4] == goal[4] && u.state.p[5] == goal[5] &&
                u.state.p[6] == goal[6] && u.state.p[7] == goal[7] && u.state.p[8] == goal[8]) {
                cout << u.step << endl;
                break;
            }
            for (int dir = 0; dir < 4; dir++) {
                State v = calNext(u.state, dir);
                int index = calIndex(v);
                if (!vis[index]) {
                    vis[index] = true;
                    v.cost = u.state.cost;
                    if (dir == 0 || dir == 1) v.cost += ch;
                    if (dir == 2 || dir == 3) v.cost += cv;
                    q.push({v, u.step + v.cost});
                }
            }
        }
    }
    return 0;
}