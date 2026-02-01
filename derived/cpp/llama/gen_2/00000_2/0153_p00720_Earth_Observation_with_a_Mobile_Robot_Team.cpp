#include <bits/stdc++.h>

using namespace std;

class Robot {
public:
    string nickname;
    vector<pair<int, pair<int, int>>> route;
    vector<int> velocities;
    vector<double> x, y;

    Robot() {}

    Robot(string nickname) : nickname(nickname) {}

    void addRoute(int t, int vx, int vy) {
        route.emplace_back(t, make_pair(vx, vy));
    }

    void calculatePositions(int T) {
        x.resize(T + 1);
        y.resize(T + 1);

        for (int i = 0; i < route.size(); ++i) {
            int t = route[i].first;
            int vx = route[i].second.first;
            int vy = route[i].second.second;

            if (i == 0) {
                x[t] = vx * t;
                y[t] = vy * t;
            } else {
                int prevT = route[i - 1].first;
                int prevVx = route[i - 1].second.first;
                int prevVy = route[i - 1].second.second;

                x[t] = x[prevT] + (vx + prevVx) * (t - prevT) / 2.0;
                y[t] = y[prevT] + (vy + prevVy) * (t - prevT) / 2.0;
            }
        }
    }
};

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T, R;
    while (cin >> N >> T >> R) {
        if (N == 0 && T == 0 && R == 0) {
            break;
        }

        vector<Robot> robots(N);
        vector<string> nicknames(N);
        for (int i = 0; i < N; ++i) {
            string nickname;
            cin >> nickname;
            nicknames[i] = nickname;
            robots[i].nickname = nickname;

            int t, x, y;
            cin >> t >> x >> y;
            robots[i].addRoute(t, x, y);

            while (cin >> t && t <= T) {
                int vx, vy;
                cin >> vx >> vy;
                robots[i].addRoute(t, vx, vy);
            }
            cin.clear();
            cin.ignore(10000, '\n');
        }

        for (int i = 0; i < N; ++i) {
            robots[i].calculatePositions(T);
        }

        DisjointSet dsu(N);

        for (int t = 0; t <= T; ++t) {
            vector<tuple<int, int, double>> events;
            for (int i = 0; i < N; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    double dx = robots[i].x[t] - robots[j].x[t];
                    double dy = robots[i].y[t] - robots[j].y[t];
                    double distance = sqrt(dx * dx + dy * dy);
                    if (distance <= R) {
                        events.emplace_back(i, j, distance);
                    }
                }
            }

            for (auto& event : events) {
                int i, j;
                tie(i, j, ignore) = event;
                dsu.unionSets(i, j);
            }
        }

        set<string> result;
        int firstRobot = 0;
        for (int i = 0; i < N; ++i) {
            if (dsu.find(i) == dsu.find(firstRobot)) {
                result.insert(robots[i].nickname);
            }
        }

        for (const auto& nickname : result) {
            cout << nickname << '\n';
        }
    }

    return 0;
}