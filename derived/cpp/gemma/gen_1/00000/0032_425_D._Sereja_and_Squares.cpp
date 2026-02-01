#include <iostream>
#include <vector>
#include <algorithm>

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

            if (x1 == x2 || y1 == y2) continue;

            int x3 = x1;
            int y3 = y2;
            int x4 = x2;
            int y4 = y1;

            bool found3 = false;
            bool found4 = false;

            for (int k = 0; k < n; ++k) {
                if (points[k].first == x3 && points[k].second == y3) {
                    found3 = true;
                }
                if (points[k].first == x4 && points[k].second == y4) {
                    found4 = true;
                }
            }

            if (found3 && found4) {
                count++;
            }
        }
    }

    cout << count / 2 << endl;

    return 0;
}