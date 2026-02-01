#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Robot {
    string nickname;
    vector<pair<int, pair<int, int>>> route;
};

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int n, t, r;
    while (cin >> n >> t >> r && (n != 0 || t != 0 || r != 0)) {
        vector<Robot> robots(n);
        for (int i = 0; i < n; ++i) {
            cin >> robots[i].nickname;
            int time;
            int x, y;
            cin >> time >> x >> y;
            robots[i].route.push_back({time, {x, y}});
            while (cin >> time >> x >> y && time <= t) {
                robots[i].route.push_back({time, {x, y}});
            }
        }

        vector<bool> informed(n, false);
        informed[0] = true;
        vector<string> result;
        result.push_back(robots[0].nickname);

        for (int time = 0; time < t; ++time) {
            for (int i = 0; i < n; ++i) {
                if (informed[i]) {
                    for (int j = 0; j < n; ++j) {
                        if (!informed[j]) {
                            int x1, y1;
                            int x2, y2;

                            // Find the position of robot i at time 'time'
                            int route_index_i = 0;
                            while (route_index_i + 1 < robots[i].route.size() && robots[i].route[route_index_i + 1].first > time) {
                                route_index_i++;
                            }
                            x1 = robots[i].route[route_index_i].second.first;
                            y1 = robots[i].route[route_index_i].second.second;

                            // Find the position of robot j at time 'time'
                            int route_index_j = 0;
                            while (route_index_j + 1 < robots[j].route.size() && robots[j].route[route_index_j + 1].first > time) {
                                route_index_j++;
                            }
                            x2 = robots[j].route[route_index_j].second.first;
                            y2 = robots[j].route[route_index_j].second.second;

                            if (distance(x1, y1, x2, y2) <= r) {
                                informed[j] = true;
                                result.push_back(robots[j].nickname);
                            }
                        }
                    }
                }
            }
        }

        sort(result.begin(), result.end());
        
        for (int i = 0; i < result.size(); ++i) {
            cout << result[i] << endl;
        }
    }

    return 0;
}