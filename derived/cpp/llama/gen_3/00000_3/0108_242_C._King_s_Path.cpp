#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

struct Position {
    int x;
    int y;
};

struct Segment {
    int row;
    int start;
    int end;

    Segment(int row, int start, int end) : row(row), start(start), end(end) {}
};

int main() {
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;

    int n;
    cin >> n;

    vector<Segment> segments(n);
    for (int i = 0; i < n; i++) {
        int row, start, end;
        cin >> row >> start >> end;
        segments[i] = Segment(row, start, end);
    }

    set<pair<int, int>> allowed;
    for (const auto& segment : segments) {
        for (int j = segment.start; j <= segment.end; j++) {
            allowed.insert({segment.row, j});
        }
    }

    queue<pair<Position, int>> q;
    q.push({{x0, y0}, 0});

    set<pair<int, int>> visited;
    visited.insert({x0, y0});

    int dx[] = {1, 0, -1, 1, -1, 1, -1, 0};
    int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        if (p.first.x == x1 && p.first.y == y1) {
            cout << p.second << endl;
            return 0;
        }

        for (int i = 0; i < 8; i++) {
            int nx = p.first.x + dx[i];
            int ny = p.first.y + dy[i];

            if (allowed.find({nx, ny}) != allowed.end() && visited.find({nx, ny}) == visited.end()) {
                q.push({{nx, ny}, p.second + 1});
                visited.insert({nx, ny});
            }
        }
    }

    cout << -1 << endl;
    return 0;
}