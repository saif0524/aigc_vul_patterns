#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;

const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Node {
    int x, y;
    vector<int> time;
    Node(int x, int y) : x(x), y(y) {
        time.resize(16, 0);
    }
};

int n;
vector<vector<int>> a;
vector<Node> nodes;

void init() {
    for (auto& node : nodes) {
        node.time = vector<int>(16, 0);
    }
}

void update(const vector<int>& cur, int x, int y) {
    for (int i = 0; i < 4; ++i) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
            Node& node = nodes[nx * 4 + ny];
            for (int j = 0; j < 16; ++j) {
                if (cur[j] == 0) {
                    node.time[j] = 0;
                } else {
                    node.time[j]++;
                }
            }
        }
    }
}

bool check(const vector<int>& cur) {
    for (int i = 0; i < 16; ++i) {
        if (cur[i] == 0 && nodes[i / 4 * 4 + i % 4].time[i] > 6) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n;
    if (n == 0) {
        return;
    }
    a.resize(n);
    for (auto& row : a) {
        row.resize(16);
    }
    nodes.resize(16);
    for (int i = 0; i < 16; ++i) {
        nodes[i] = Node(i / 4, i % 4);
    }
    init();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 16; ++j) {
            cin >> a[i][j];
        }
        update(a[i], 1, 1);
    }
    if (!check(a[n - 1])) {
        cout << 0 << '\n';
        return;
    }
    queue<pair<vector<int>, int>> q;
    q.push({a[n - 1], n - 1});
    unordered_set<vector<int>> vis;
    while (!q.empty()) {
        auto [cur, t] = q.front();
        q.pop();
        if (t == 0) {
            cout << 1 << '\n';
            return;
        }
        if (!vis.insert(cur).second) {
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            int x = i / 2;
            int y = i % 2;
            for (int j = 0; j < 4; ++j) {
                int nx = x + dir[j][0];
                int ny = y + dir[j][1];
                if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
                    vector<int> nxt = cur;
                    int xx = nx * 2;
                    int yy = ny * 2;
                    for (int k = 0; k < 2; ++k) {
                        for (int l = 0; l < 2; ++l) {
                            int idx = (xx + k) * 4 + yy + l;
                            nxt[idx] ^= 1;
                        }
                    }
                    if (check(nxt)) {
                        q.push({nxt, t - 1});
                    }
                }
            }
        }
        x = 1;
        y = 1;
        for (int j = 0; j < 4; ++j) {
            int nx = x + dir[j][0];
            int ny = y + dir[j][1];
            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                vector<int> nxt = cur;
                int xx = nx * 2;
                int yy = ny * 2;
                for (int k = 0; k < 2; ++k) {
                    for (int l = 0; l < 2; ++l) {
                        int idx = (xx + k) * 4 + yy + l;
                        nxt[idx] ^= 1;
                    }
                }
                if (check(nxt)) {
                    q.push({nxt, t - 1});
                }
            }
        }
    }
    cout << 0 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        solve();
    }
}