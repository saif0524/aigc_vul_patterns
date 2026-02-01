#include <bits/stdc++.h>
using namespace std;

struct Robot {
    string nickname;
    vector<pair<int, pair<int, int>>> moves;
    pair<int, int> positionAt(int t) {
        for (int i = 0; i < moves.size() - 1; ++i) {
            if (t < moves[i + 1].first) {
                int dt = t - moves[i].first;
                return {moves[i].second.first + dt * moves[i + 1].second.first,
                        moves[i].second.second + dt * moves[i + 1].second.second};
            }
        }
        return moves.back().second;
    }
};

double dist(pair<int, int> a, pair<int, int> b) {
    return hypot(a.first - b.first, a.second - b.second);
}

int main() {
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
                int t, vx, vy;
                cin >> t >> vx >> vy;
                robot.moves.push_back({t, {vx, vy}});
            }
        }
        vector<bool> hasData(N, false);
        hasData[0] = true;
        for (int t = 0; t <= T; ++t) {
            vector<int> toReceive;
            for (int i = 0; i < N; ++i) {
                if (hasData[i]) {
                    for (int j = 0; j < N; ++j) {
                        if (!hasData[j] && dist(robots[i].positionAt(t), robots[j].positionAt(t)) <= R) {
                            toReceive.push_back(j);
                        }
                    }
                }
            }
            for (int j : toReceive) {
                hasData[j] = true;
            }
        }
        vector<string> result;
        for (int i = 0; i < N; ++i) {
            if (hasData[i]) {
                result.push_back(robots[i].nickname);
            }
        }
        sort(result.begin(), result.end());
        for (const string& name : result) {
            cout << name << "\n";
        }
    }
}