#include <bits/stdc++.h>
using namespace std;

struct State {
    int board[9];
    int empty;
    int cost;
    bool operator<(const State& o) const {
        return cost > o.cost;
    }
};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
int cost_hv[] = {0, 0, 0, 0};

int heuristic(const State& state, const State& goal) {
    int h = 0;
    for (int i = 0; i < 9; i++) {
        if (state.board[i] != 0 && state.board[i] != goal.board[i]) {
            for (int j = 0; j < 9; j++) {
                if (goal.board[j] == state.board[i]) {
                    int r1 = i / 3, c1 = i % 3;
                    int r2 = j / 3, c2 = j % 3;
                    int dh = min(abs(r1 - r2), 3 - abs(r1 - r2));
                    int dv = min(abs(c1 - c2), 3 - abs(c1 - c2));
                    h += dh * cost_hv[2] + dv * cost_hv[3];
                }
            }
        }
    }
    return h;
}

int manhattan_distance(int a, int b) {
    int x1 = a / 3, y1 = a % 3;
    int x2 = b / 3, y2 = b % 3;
    return min(abs(x1 - x2), 3 - abs(x1 - x2)) + min(abs(y1 - y2), 3 - abs(y1 - y2));
}

int get_empty(const vector<int>& board) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == 0) return i;
    }
    return -1;
}

int encode(const vector<int>& board) {
    int code = 0;
    for (int num : board) {
        code = code * 9 + num;
    }
    return code;
}

int solve(const State& start, const State& goal) {
    priority_queue<State> pq;
    pq.push(start);
    unordered_map<int, int> visited;
    visited[encode(vector<int>(start.board, start.board + 9))] = 0;

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (memcmp(current.board, goal.board, sizeof(current.board)) == 0) {
            return current.cost;
        }

        int x = current.empty / 3, y = current.empty % 3;
        for (int dir = 0; dir < 4; dir++) {
            int nx = (x + dr[dir] + 3) % 3;
            int ny = (y + dc[dir] + 3) % 3;
            int nempty = nx * 3 + ny;
            State next = current;
            next.board[current.empty] = next.board[nempty];
            next.board[nempty] = 0;
            next.empty = nempty;
            next.cost += dir < 2 ? cost_hv[0] : cost_hv[1];

            int code = encode(vector<int>(next.board, next.board + 9));
            if (visited.find(code) == visited.end() || visited[code] > next.cost) {
                visited[code] = next.cost;
                pq.push(next);
            }
        }
    }
    return -1;
}

int main() {
    while (true) {
        int ch, cv;
        cin >> ch >> cv;
        if (ch == 0 && cv == 0) break;
        cost_hv[0] = cost_hv[2] = ch;
        cost_hv[1] = cost_hv[3] = cv;

        State start, goal;
        for (int i = 0; i < 9; i++) {
            int x;
            cin >> x;
            start.board[i] = x;
            if (x == 0) start.empty = i;
        }
        for (int i = 0; i < 9; i++) {
            int x;
            cin >> x;
            goal.board[i] = x;
            if (x == 0) goal.empty = i;
        }

        start.cost = 0;
        cout << solve(start, goal) << "\n";
    }
}