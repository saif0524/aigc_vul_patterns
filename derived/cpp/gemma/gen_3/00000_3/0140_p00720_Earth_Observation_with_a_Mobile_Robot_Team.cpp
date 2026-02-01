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

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int n, t, r;
    while (cin >> n >> t >> r && (n != 0 || t != 0 || r != 0)) {
        vector<Robot> robots(n);
        for (int i = 0; i < n; ++i) {
            cin >> robots[i].nickname;
            int time;
            while (cin >> time) {
                int x, y;
                cin >> x >> y;
                robots[i].route.push_back({time, {x, y}});
                if (time == t) break;
            }
        }

        vector<string> informed_robots;
        informed_robots.push_back(robots[0].nickname);
        vector<bool> visited(n, false);
        visited[0] = true;
        
        for (int time = 0; time < t; ++time) {
            vector<string> newly_informed;
            for (int i = 0; i < n; ++i) {
                if (visited[i]) {
                    for (int j = 0; j < n; ++j) {
                        if (!visited[j]) {
                            int x1, y1, x2, y2;
                            
                            // Find position of robot i at time 'time'
                            int route_idx_i = 0;
                            while (route_idx_i + 1 < robots[i].route.size() && robots[i].route[route_idx_i + 1].first > time) {
                                route_idx_i++;
                            }
                            x1 = robots[i].route[route_idx_i].second.first;
                            y1 = robots[i].route[route_idx_i].second.second;
                            
                            // Find position of robot j at time 'time'
                            int route_idx_j = 0;
                            while (route_idx_j + 1 < robots[j].route.size() && robots[j].route[route_idx_j + 1].first > time) {
                                route_idx_j++;
                            }
                            x2 = robots[j].route[route_idx_j].second.first;
                            y2 = robots[j].route[route_idx_j].second.second;
                            
                            if (dist(x1, y1, x2, y2) <= r) {
                                newly_informed.push_back(robots[j].nickname);
                                visited[j] = true;
                            }
                        }
                    }
                }
            }
            
            for (const string& robot_name : newly_informed) {
                informed_robots.push_back(robot_name);
            }
        }
        
        sort(informed_robots.begin(), informed_robots.end());
        
        for (const string& robot_name : informed_robots) {
            cout << robot_name << endl;
        }
    }

    return 0;
}