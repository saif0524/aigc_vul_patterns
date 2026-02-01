#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

struct Robot {
    string nickname;
    vector<pair<int, pair<double, double>>> positions;
    vector<pair<int, pair<double, double>>> velocities;
};

struct Event {
    int time;
    int robot1;
    int robot2;
    bool enter;
};

bool operator<(const Event& a, const Event& b) {
    return a.time < b.time;
}

double distance(const pair<double, double>& a, const pair<double, double>& b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

void solve() {
    int N, T, R;
    cin >> N >> T >> R;

    if (N == 0) return;

    vector<Robot> robots(N);
    for (int i = 0; i < N; ++i) {
        cin >> robots[i].nickname;

        int t;
        double x, y;
        cin >> t >> x >> y;
        robots[i].positions.emplace_back(t, make_pair(x, y));

        while (t < T) {
            int tn;
            double vx, vy;
            cin >> tn >> vx >> vy;
            robots[i].velocities.emplace_back(t, make_pair(vx, vy));
            robots[i].positions.emplace_back(tn, make_pair(x + vx * (tn - t), y + vy * (tn - t)));
            t = tn;
            x += vx * (tn - t);
            y += vy * (tn - t);
        }
    }

    vector<Event> events;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = 0; k < robots[i].positions.size() - 1; ++k) {
                for (int l = 0; l < robots[j].positions.size() - 1; ++l) {
                    double t1 = robots[i].positions[k].first;
                    double t2 = robots[i].positions[k + 1].first;
                    double x1 = robots[i].positions[k].second.first;
                    double y1 = robots[i].positions[k].second.second;
                    double vx1 = robots[i].velocities[k].second.first;
                    double vy1 = robots[i].velocities[k].second.second;

                    double t3 = robots[j].positions[l].first;
                    double t4 = robots[j].positions[l + 1].first;
                    double x2 = robots[j].positions[l].second.first;
                    double y2 = robots[j].positions[l].second.second;
                    double vx2 = robots[j].velocities[l].second.first;
                    double vy2 = robots[j].velocities[l].second.second;

                    if (t1 > t4 || t3 > t2) continue;

                    double t = max(t1, t3);
                    double x = x1 + vx1 * (t - t1);
                    double y = y1 + vy1 * (t - t1);
                    double x_ = x2 + vx2 * (t - t3);
                    double y_ = y2 + vy2 * (t - t3);

                    if (distance(make_pair(x, y), make_pair(x_, y_)) <= R) {
                        events.emplace_back(int(t * 1000000 + 0.5), i, j, true);
                    }

                    t = min(t2, t4);
                    x = x1 + vx1 * (t - t1);
                    y = y1 + vy1 * (t - t1);
                    x_ = x2 + vx2 * (t - t3);
                    y_ = y2 + vy2 * (t - t3);

                    if (distance(make_pair(x, y), make_pair(x_, y_)) <= R) {
                        events.emplace_back(int(t * 1000000 + 0.5), i, j, false);
                    }
                }
            }
        }
    }

    sort(events.begin(), events.end());

    set<pair<int, int>> graph;
    for (const auto& event : events) {
        if (event.enter) {
            graph.insert(make_pair(event.robot1, event.robot2));
            graph.insert(make_pair(event.robot2, event.robot1));
        } else {
            graph.erase(make_pair(event.robot1, event.robot2));
            graph.erase(make_pair(event.robot2, event.robot1));
        }
    }

    set<string> result;
    set<int> visited;
    function<void(int)> dfs = [&](int node) {
        visited.insert(node);
        result.insert(robots[node].nickname);
        for (const auto& edge : graph) {
            if (edge.first == node && visited.find(edge.second) == visited.end()) {
                dfs(edge.second);
            }
        }
    };

    dfs(0);

    for (const auto& robot : result) {
        cout << robot << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        solve();
    }

    return 0;
}