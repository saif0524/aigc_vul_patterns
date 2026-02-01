#include <bits/stdc++.h>
using namespace std;

struct Puzzle {
    int board[3][3];
    pair<int, int> empty;
};

struct Node {
    Puzzle puzzle;
    int cost;
    int g;

    bool operator<(const Node& other) const {
        return cost + g > other.cost + other.g;
    }
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ch, cv;

bool isValid(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

Puzzle move(Puzzle p, int dir) {
    Puzzle np = p;
    int nx = p.empty.first + dx[dir];
    int ny = p.empty.second + dy[dir];
    if (nx == 3) nx = 0;
    if (nx == -1) nx = 2;
    if (ny == 3) ny = 0;
    if (ny == -1) ny = 2;
    np.board[p.empty.first][p.empty.second] = p.board[nx][ny];
    np.board[nx][ny] = 0;
    np.empty = {nx, ny};
    return np;
}

int heuristic(Puzzle& p, Puzzle& goal) {
    int h = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (p.board[i][j] != goal.board[i][j]) {
                for (int ii = 0; ii < 3; ii++) {
                    for (int jj = 0; jj < 3; jj++) {
                        if (p.board[i][j] == goal.board[ii][jj]) {
                            int x_diff = abs(i - ii);
                            int y_diff = abs(j - jj);
                            x_diff = min(x_diff, 3 - x_diff);
                            y_diff = min(y_diff, 3 - y_diff);
                            h += x_diff * cv + y_diff * ch;
                        }
                    }
                }
            }
        }
    }
    return h;
}

bool operator==(const Puzzle& p1, const Puzzle& p2) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (p1.board[i][j] != p2.board[i][j]) return false;
        }
    }
    return true;
}

namespace std {
    template<>
    struct hash<Puzzle> {
        size_t operator()(const Puzzle& p) const {
            size_t res = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    res = res * 9 + p.board[i][j];
                }
            }
            return res;
        }
    };
}

int solve(Puzzle& start, Puzzle& goal) {
    priority_queue<Node> pq;
    unordered_set<Puzzle> visited;
    pq.push({start, 0, 0});
    visited.insert(start);
    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        Puzzle puzzle = node.puzzle;
        int cost = node.cost;
        int g = node.g;
        if (puzzle == goal) return g;
        for (int dir = 0; dir < 4; dir++) {
            Puzzle np = move(puzzle, dir);
            if (!visited.count(np)) {
                int ncost = cost + (dir % 2 ? ch : cv);
                int ng = g + ncost;
                pq.push({np, ncost, ng});
                visited.insert(np);
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> ch >> cv && (ch || cv)) {
        Puzzle start, goal;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> start.board[i][j];
                if (start.board[i][j] == 0) start.empty = {i, j};
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> goal.board[i][j];
                if (goal.board[i][j] == 0) goal.empty = {i, j};
            }
        }
        cout << solve(start, goal) << "\n";
    }
}