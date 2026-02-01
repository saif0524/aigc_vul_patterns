#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Robot {
    string nickname;
    int T;
    vector<pair<int, pair<int, int>>> route;
};

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int N, T, R;
    while (cin >> N >> T >> R && (N != 0 || T != 0 || R != 0)) {
        vector<Robot> robots(N);
        for (int i = 0; i < N; ++i) {
            cin >> robots[i].nickname;
            cin >> robots[i].T;
            for (int j = 0; j <= robots[i].T; ++j) {
                int t, vx, vy;
                cin >> t >> vx >> vy;
                robots[i].route.push_back({t, {vx, vy}});
            }
        }

        vector<string> informed_robots;
        informed_robots.push_back(robots[0].nickname);

        vector<bool> visited(N, false);
        visited[0] = true;

        for (int time = 0; time < T; ++time) {
            
            vector<int> newly_informed;

            for (int i = 0; i < N; ++i) {
                if (visited[i]) continue;

                for (int j = 0; j < N; ++j) {
                    if (visited[j]) {
                        int x1, y1, x2, y2;

                        // Find position of robot j at time 'time'
                        int t1 = -1;
                        for (int k = 0; k < robots[j].route.size(); ++k) {
                            if (robots[j].route[k].first == time) {
                                t1 = k;
                                break;
                            } else if (robots[j].route[k].first > time) {
                                t1 = k - 1;
                                break;
                            }
                        }
                        if (t1 == -1) t1 = robots[j].route.size() -1;

                        int t2 = -1;
                        for (int k = 0; k < robots[i].route.size(); ++k) {
                            if (robots[i].route[k].first == time) {
                                t2 = k;
                                break;
                            } else if (robots[i].route[k].first > time) {
                                t2 = k - 1;
                                break;
                            }
                        }
                        if (t2 == -1) t2 = robots[i].route.size() - 1;
                        
                        
                        if(t1 == -1 || t2 == -1){
                            continue;
                        }

                        int vx1 = robots[j].route[t1].second.first;
                        int vy1 = robots[j].route[t1].second.second;
                        int vx2 = robots[i].route[t2].second.first;
                        int vy2 = robots[i].route[t2].second.second;
                        
                        int x_j = 0, y_j = 0, x_i = 0, y_i = 0;
                       
                       if(t1 == 0){
                            x_j = robots[j].route[0].second.first * robots[j].route[0].first;
                            y_j = robots[j].route[0].second.second * robots[j].route[0].first;
                       } else {
                            int prev_t = robots[j].route[t1-1].first;
                            x_j = robots[j].route[t1-1].second.first * (time - prev_t) + robots[j].route[t1-1].second.first;
                            y_j = robots[j].route[t1-1].second.second * (time - prev_t) + robots[j].route[t1-1].second.second;
                       }
                        
                        if(t2 == 0){
                            x_i = robots[i].route[0].second.first * robots[i].route[0].first;
                            y_i = robots[i].route[0].second.second * robots[i].route[0].first;
                        } else {
                            int prev_t = robots[i].route[t2-1].first;
                            x_i = robots[i].route[t2-1].second.first * (time - prev_t) + robots[i].route[t2-1].second.first;
                            y_i = robots[i].route[t2-1].second.second * (time - prev_t) + robots[i].route[t2-1].second.second;
                            
                           
                        }
                        
                        

                        if (dist(x_j, y_j, x_i, y_i) <= R) {
                            newly_informed.push_back(i);
                            break;
                        }
                    }
                }
            }

            for (int robot_index : newly_informed) {
                informed_robots.push_back(robots[robot_index].nickname);
                visited[robot_index] = true;
            }
        }

        sort(informed_robots.begin(), informed_robots.end());
        for (const string& robot_name : informed_robots) {
            cout << robot_name << endl;
        }
    }

    return 0;
}