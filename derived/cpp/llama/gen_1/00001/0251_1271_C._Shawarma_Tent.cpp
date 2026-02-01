#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n, sx, sy;
    cin >> n >> sx >> sy;

    vector<Point> students(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i].x >> students[i].y;
    }

    map<int, set<int>> xMap, yMap;
    map<int, int> countMap;
    for (const auto& student : students) {
        int dx = student.x - sx;
        int dy = student.y - sy;
        if (dx >= 0 && dy >= 0) {
            xMap[dx].insert(student.x);
            yMap[dy].insert(student.y);
        } else if (dx <= 0 && dy >= 0) {
            xMap[-dx].insert(student.x);
            yMap[dy].insert(student.y);
        } else if (dx <= 0 && dy <= 0) {
            xMap[-dx].insert(student.x);
            yMap[-dy].insert(student.y);
        } else {
            xMap[dx].insert(student.x);
            yMap[-dy].insert(student.y);
        }
    }

    int maxXCount = 0;
    int maxYCount = 0;
    int maxX = 0;
    int maxY = 0;
    for (const auto& xPair : xMap) {
        if (xPair.second.size() > maxXCount) {
            maxXCount = xPair.second.size();
            maxX = xPair.first;
        }
    }

    for (const auto& yPair : yMap) {
        if (yPair.second.size() > maxYCount) {
            maxYCount = yPair.second.size();
            maxY = yPair.first;
        }
    }

    if (maxXCount > maxYCount) {
        int bestX = sx + (sx > maxX ? -maxX : maxX);
        int bestY = yMap[abs(maxX)].begin()->y;
        cout << maxXCount << endl;
        cout << bestX << " " << bestY << endl;
    } else if (maxYCount > maxXCount) {
        int bestX = xMap[abs(maxY)].begin()->x;
        int bestY = sy + (sy > maxY ? -maxY : maxY);
        cout << maxYCount << endl;
        cout << bestX << " " << bestY << endl;
    } else {
        int bestX1 = sx + (sx > maxX ? -maxX : maxX);
        int bestY1 = yMap[abs(maxX)].begin()->y;
        int bestX2 = xMap[abs(maxY)].begin()->x;
        int bestY2 = sy + (sy > maxY ? -maxY : maxY);
        int count1 = 0;
        int count2 = 0;
        for (const auto& student : students) {
            if (bestX1 <= max(student.x, sx) && bestX1 >= min(student.x, sx) &&
                bestY1 <= max(student.y, sy) && bestY1 >= min(student.y, sy)) {
                count1++;
            }
            if (bestX2 <= max(student.x, sx) && bestX2 >= min(student.x, sx) &&
                bestY2 <= max(student.y, sy) && bestY2 >= min(student.y, sy)) {
                count2++;
            }
        }
        if (count1 > count2) {
            cout << count1 << endl;
            cout << bestX1 << " " << bestY1 << endl;
        } else {
            cout << count2 << endl;
            cout << bestX2 << " " << bestY2 << endl;
        }
    }

    return 0;
}