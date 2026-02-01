#include <bits/stdc++.h>

using namespace std;

double getDistance(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
    while(1) {
        int N, T, R;
        scanf("%d%d%d", &N, &T, &R);
        if (N == 0 && T == 0 && R == 0) {
            break;
        }

        string nickname[N];
        pair<double, double> position[N][T+1];
        bool hasData[N];
        bool inRange[N][N][T+1];

        for (int r = 0; r < N; r++) {
            cin >> nickname[r];
            vector<tuple<int, double, double>> route;
            int time, x, y;
            scanf("%d%d%d", &time, &x, &y);
            route.push_back({time, (double)x, (double)y});
            for (int i = 1; i < T+1; i++) {
                scanf("%d%d%d", &time, &x, &y);
                route.push_back({time, (double)x, (double)y});
            }
            for (int t = 0; t < T+1; t++) {
                if (t == 0) {
                    position[r][t] = { route[0].second, route[0].third };
                } else {
                    pair<int, double> prevTime;
                    int i;
                    for (i = route.size()-1; i >= 0; i--) {
                        prevTime = {route[i].first, route[i].second};
                        if (prevTime.first <= t) {
                            break;
                        }
                    }
                    if (i == -1) {
                        position[r][t] = { route[0].second, route[0].third };
                    } else {
                        double dt = (double)(t - prevTime.first) / (route[i+1].first - prevTime.first);
                        position[r][t].first = prevTime.second + dt * (route[i+1].second - prevTime.second);
                        position[r][t].second = route[i+1].third + dt * (route[i+1].third - route[i].third);
                    }
                }
            }
            hasData[r] = (r == 0);
        }

        for (int t = 0; t < T+1; t++) {
            for (int r1 = 0; r1 < N; r1++) {
                for (int r2 = r1+1; r2 < N; r2++) {
                    double distance = getDistance(position[r1][t].first, position[r1][t].second,
                                                position[r2][t].first, position[r2][t].second);
                    inRange[r1][r2][t] = (distance <= R);
                    inRange[r2][r1][t] = (distance <= R);
                }
            }
        }

        vector<bool> visited(N);
        set<string> dataRobots;
        dataRobots.insert(nickname[0]);
        visited[0] = true;
        for (int t = T; t >= 0; t--) {
            for (int r = 0; r < N; r++) {
                if (visited[r]) {
                    for (int rr = 0; rr < N; rr++) {
                        if (inRange[r][rr][t]) {
                            visited[rr] = true;
                            dataRobots.insert(nickname[rr]);
                            hasData[rr] = true;
                        }
                    }
                }
            }
        }

        for (auto robot : dataRobots) {
            cout << robot << endl;
        }
    }

    return 0;
}