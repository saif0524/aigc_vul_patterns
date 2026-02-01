#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int x1 = points[i].first;
            int y1 = points[i].second;
            int x2 = points[j].first;
            int y2 = points[j].second;

            if (x1 != x2 && y1 != y2) {
                int x3 = x1;
                int y3 = y2;
                int x4 = x2;
                int y4 = y1;

                set<pair<int, int>> point_set;
                for (int k = 0; k < n; ++k) {
                    point_set.insert(points[k]);
                }

                if (point_set.count({x3, y3}) && point_set.count({x4, y4})) {
                    count++;
                }
            }
        }
    }

    cout << count / 2 << endl;

    return 0;
}