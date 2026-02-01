#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct Point {
    double x, y;
};

struct Robot {
    string name;
    vector<pair<int, Point>> positions;
};

double distance(const Point& p1, const Point& p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    int N, T, R;
    while (cin >> N >> T >> R) {
        if (N == 0 && T == 0 && R == 0) break;
        vector<Robot> robots(N);
        map<string, int> nameIndex;
        for (int i = 0; i < N; ++i) {
            cin >> robots[i].name;
            nameIndex[robots[i].name] = i;
            int k;
            cin >> k;
            while (k--) {
                int t, vx, vy;
                cin >> t >> vx >> vy;
                if (robots[i].positions.empty()) {
                    robots[i].positions.push_back({t, {vx, vy}});
                } else {
                    Point last = robots[i].positions.back().second;
                    robots[i].positions.push_back({t, {last.x + vx * (t - robots[i].positions.back().first),
                                                      last.y + vy * (t - robots[i].positions.back().first)}});
                }
            }
        }

        vector<bool> hasData(N, false);
        hasData[0] = true;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (int other = 0; other < N; ++other) {
                if (!hasData[other]) {
                    bool canCommunicate = true;
                    for (int t = 0; t <= T; ++t) {
                        Point p1, p2;
                        if (t <= robots[current].positions[0].first) {
                            p1 = robots[current].positions[0].second;
                        } else if (t >= robots[current].positions.back().first) {
                            p1 = robots[current].positions.back().second;
                        } else {
                            for (size_t i = 1; i < robots[current].positions.size(); ++i) {
                                if (t <= robots[current].positions[i].first) {
                                    double fraction = (t - robots[current].positions[i - 1].first) /
                                                      (double)(robots[current].positions[i].first - robots[current].positions[i - 1].first);
                                    p1.x = robots[current].positions[i - 1].second.x + fraction *
                                                                 (robots[current].positions[i].second.x - robots[current].positions[i - 1].second.x);
                                    p1.y = robots[current].positions[i - 1].second.y + fraction *
                                                                 (robots[current].positions[i].second.y - robots[current].positions[i - 1].second.y);
                                    break;
                                }
                            }
                        }
                        if (t <= robots[other].positions[0].first) {
                            p2 = robots[other].positions[0].second;
                        } else if (t >= robots[other].positions.back().first) {
                            p2 = robots[other].positions.back().second;
                        } else {
                            for (size_t i = 1; i < robots[other].positions.size(); ++i) {
                                if (t <= robots[other].positions[i].first) {
                                    double fraction = (t - robots[other].positions[i - 1].first) /
                                                      (double)(robots[other].positions[i].first - robots[other].positions[i - 1].first);
                                    p2.x = robots[other].positions[i - 1].second.x + fraction *
                                                                 (robots[other].positions[i].second.x - robots[other].positions[i - 1].second.x);
                                    p2.y = robots[other].positions[i - 1].second.y + fraction *
                                                                 (robots[other].positions[i].second.y - robots[other].positions[i - 1].second.y);
                                    break;
                                }
                            }
                        }
                        if (distance(p1, p2) <= R) {
                            canCommunicate = true;
                            break;
                        }
                    }
                    if (canCommunicate) {
                        hasData[other] = true;
                        q.push(other);
                    }
                }
            }
        }

        vector<string> result;
        for (int i = 0; i < N; ++i) {
            if (hasData[i]) result.push_back(robots[i].name);
        }
        sort(result.begin(), result.end());
        for (const auto& name : result) {
            cout << name << endl;
        }
    }
}