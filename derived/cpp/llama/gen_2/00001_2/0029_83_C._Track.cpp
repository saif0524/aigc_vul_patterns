#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;
    string path;
    int type[26];

    Node(int x, int y, string path, int type[26]) : x(x), y(y), path(path) {
        for (int i = 0; i < 26; i++) {
            this->type[i] = type[i];
        }
    }
};

struct Compare {
    bool operator()(const Node& a, const Node& b) {
        return a.path > b.path;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int sx, sy, tx, ty;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (grid[i][j] == 'T') {
                tx = i;
                ty = j;
            }
        }
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    priority_queue<Node, vector<Node>, Compare> pq;
    int type[26] = {0};
    pq.push(Node(sx, sy, "", type));

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();

        int x = node.x;
        int y = node.y;
        string path = node.path;

        if (x == tx && y == ty) {
            cout << path << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            int nt[26];
            for (int j = 0; j < 26; j++) {
                nt[j] = node.type[j];
            }

            char c = grid[nx][ny];
            if (c == 'S' || c == 'T') {
                continue;
            }

            int idx = c - 'a';
            nt[idx]++;

            int count = 0;
            for (int j = 0; j < 26; j++) {
                if (nt[j] > 0) {
                    count++;
                }
            }

            if (count > k) {
                continue;
            }

            string npath = path + c;
            pq.push(Node(nx, ny, npath, nt));
        }
    }

    cout << -1 << endl;
    return 0;
}