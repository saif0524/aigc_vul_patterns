#include <bits/stdc++.h>
using namespace std;

struct Robot {
    string nickname;
    vector<pair<int, pair<int, int>>> route;
};

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

pair<int, int> getPosition(const Robot& robot, int t) {
    int idx = 0;
    while (idx < robot.route.size() - 1 && robot.route[idx + 1].first <= t) {
        ++idx;
    }
    int t1 = robot.route[idx].first, t2 = robot.route[idx + 1].first;
    int x1 = robot.route[idx].second.first, y1 = robot.route[idx].second.second;
    int vx2 = robot.route[idx + 1].second.first, vy2 = robot.route[idx + 1].second.second;
    int x = x1 + vx2 * (t - t1), y = y1 + vy2 * (t - t1);
    return {x, y};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true) {
        int N, T, R;
        cin >> N >> T >> R;
        if (N == 0 && T == 0 && R == 0) break;
        vector<Robot> robots(N);
        for (auto& robot : robots) {
            cin >> robot.nickname;
            int k;
            cin >> k;
            for (int i = 0; i < k; ++i) {
                int t, x, y;
                cin >> t >> x >> y;
                robot.route.emplace_back(t, make_pair(x, y));
            }
        }
        vector<bool> informed(N, false);
        set<string> informedSet;
        queue<int> q;
        informed[0] = true;
        informedSet.insert(robots[0].nickname);
        q.push(0);
        for (int t = 0; t <= T; ++t) {
            vector<int> toInform;
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                for (int j = 0; j < N; ++j) {
                    if (!informed[j]) {
                        auto p1 = getPosition(robots[i], t);
                        auto p2 = getPosition(robots[j], t);
                        if (distance(p1.first, p1.second, p2.first, p2.second) <= R) {
                            toInform.push_back(j);
                            informed[j] = true;
                            informedSet.insert(robots[j].nickname);
                        }
                    }
                }
            }
            for (int j : toInform) {
                q.push(j);
            }
        }
        for (const auto& nickname : informedSet) {
            cout << nickname << '\n';
        }
    }
}