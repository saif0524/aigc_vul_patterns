#include <bits/stdc++.h>
using namespace std;

struct State {
    int r, c, k, d;
    bool operator<(const State &other) const {
        return d > other.d;
    }
};

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> A(H);
    for (auto &a : A) cin >> a;
    int sr = -1, sc = -1;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] == 'S') {
                sr = i;
                sc = j;
                break;
            }
        }
    }
    vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(W, vector<bool>(K + 1, false)));
    priority_queue<State> pq;
    pq.push({sr, sc, K, 0});
    visited[sr][sc][K] = true;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    while (!pq.empty()) {
        auto [r, c, k, d] = pq.top();
        pq.pop();
        if (r == 0 || r == H - 1 || c == 0 || c == W - 1) {
            cout << d;
            return 0;
        }
        for (int i = 0; i <= k; ++i) {
            int nr = r, nc = c;
            for (const auto &[dr, dc] : directions) {
                nr = r + dr;
                nc = c + dc;
                if (nr >= 0 && nr < H && nc >= 0 && nc < W && A[nr][nc] != '#') {
                    if (!visited[nr][nc][k - i]) {
                        visited[nr][nc][k - i] = true;
                        pq.push({nr, nc, k - i, d + (i > 0)});
                    }
                    nr += dr;
                    nc += dc;
                }
            }
            for (int cr = max(0, r - K); cr <= min(H - 1, r + K); ++cr) {
                for (int cc = max(0, c - K); cc <= min(W - 1, c + K); ++cc) {
                    if (A[cr][cc] == '#') {
                        A[cr][cc] = '.';
                        if (!visited[cr][cc][k - i - 1]) {
                            visited[cr][cc][k - i - 1] = true;
                            pq.push({cr, cc, k - i - 1, d + (i > 0) + (k - i > 0)});
                        }
                        A[cr][cc] = '#';
                    }
                }
            }
        }
    }
    cout << -1;
    return 0;
}