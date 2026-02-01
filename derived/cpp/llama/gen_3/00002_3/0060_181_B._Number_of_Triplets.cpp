#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
    }
    set<pair<int, int>> point_set(points.begin(), points.end());
    int count = 0;
    for (int a = 0; a < n; ++a) {
        for (int c = a + 1; c < n; ++c) {
            int x = (points[a].first + points[c].first);
            int y = (points[a].second + points[c].second);
            if (x % 2 == 0 && y % 2 == 0) {
                pair<int, int> middle = {x / 2, y / 2};
                if (point_set.find(middle) != point_set.end()) {
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}