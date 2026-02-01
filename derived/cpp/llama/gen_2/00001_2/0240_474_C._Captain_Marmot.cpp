#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Mole {
    int x, y, a, b;
};

vector<pair<int, int>> rotate(const pair<int, int>& p, const pair<int, int>& center, int times) {
    vector<pair<int, int>> result;
    for (int i = 0; i <= times; i++) {
        int newX = center.first + (p.first - center.first) * cos(i * M_PI / 2) - (p.second - center.second) * sin(i * M_PI / 2);
        int newY = center.second + (p.first - center.first) * sin(i * M_PI / 2) + (p.second - center.second) * cos(i * M_PI / 2);
        result.push_back({newX, newY});
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<Mole> moles;
    for (int i = 0; i < 4 * n; i++) {
        Mole m;
        cin >> m.x >> m.y >> m.a >> m.b;
        moles.push_back(m);
    }
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> positions;
        for (int j = 0; j < 4; j++) {
            int index = i * 4 + j;
            positions.push_back({moles[index].x, moles[index].y});
        }
        bool found = false;
        for (int p1 = 0; p1 < 4; p1++) {
            for (int p2 = 0; p2 < 4; p2++) {
                for (int p3 = 0; p3 < 4; p3++) {
                    for (int p4 = 0; p4 < 4; p4++) {
                        if (p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) {
                            continue;
                        }
                        int x1 = positions[p1].first;
                        int y1 = positions[p1].second;
                        int x2 = positions[p2].first;
                        int y2 = positions[p2].second;
                        int x3 = positions[p3].first;
                        int y3 = positions[p3].second;
                        int x4 = positions[p4].first;
                        int y4 = positions[p4].second;
                        double d12 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
                        double d23 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
                        double d34 = sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2));
                        double d41 = sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));
                        if (abs(d12 - d23) < 1e-9 && abs(d23 - d34) < 1e-9 && abs(d34 - d41) < 1e-9 && abs(d12 - d41) < 1e-9) {
                            vector<pair<int, int>> center = {{(x1 + x2 + x3 + x4) / 4, (y1 + y2 + y3 + y4) / 4}};
                            int moves = 0;
                            for (int j = 0; j < 4; j++) {
                                int index = i * 4 + j;
                                auto rotations = rotate({moles[index].x, moles[index].y}, {moles[index].a, moles[index].b}, 3);
                                for (int k = 0; k < 4; k++) {
                                    if (abs(rotations[k].first - center[0].first - (center[0].first - positions[p1].first)) < 1e-9 && abs(rotations[k].second - center[0].second - (center[0].second - positions[p1].second)) < 1e-9) {
                                        moves += k;
                                        break;
                                    }
                                }
                            }
                            cout << moves << endl;
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        if (!found) {
            cout << "-1" << endl;
        }
    }
    return 0;
}