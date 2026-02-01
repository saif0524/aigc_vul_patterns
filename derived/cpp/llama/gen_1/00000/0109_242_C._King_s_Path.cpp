#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
const int MOVES[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

struct Segment {
    int row, start, end;
};

bool isValid(int x, int y, const vector<Segment>& segments) {
    for (const auto& segment : segments) {
        if (segment.row == x && segment.start <= y && y <= segment.end) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;

    int n;
    cin >> n;

    vector<Segment> segments(n);
    for (auto& segment : segments) {
        cin >> segment.row >> segment.start >> segment.end;
    }

    deque<pair<int, int>> queue;
    queue.push_back({x0, y0});
    vector<vector<int>> distance(MAX_N, vector<int>(MAX_N, -1));
    distance[x0][y0] = 0;

    while (!queue.empty()) {
        auto [x, y] = queue.front();
        queue.pop_front();

        for (const auto& move : MOVES) {
            int newX = x + move[0];
            int newY = y + move[1];

            if (newX < 1 || newX > 100 || newY < 1 || newY > 100) {
                continue;
            }

            if (!isValid(newX, newY, segments)) {
                continue;
            }

            if (distance[newX][newY] != -1) {
                continue;
            }

            distance[newX][newY] = distance[x][y] + 1;
            queue.push_back({newX, newY});
        }
    }

    cout << distance[x1][y1] << endl;

    return 0;
}