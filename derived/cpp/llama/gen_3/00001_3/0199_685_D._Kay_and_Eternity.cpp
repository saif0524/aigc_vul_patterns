#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    map<int, int> count;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = min(points[i].first, points[j].first);
            int y1 = min(points[i].second, points[j].second);
            int x2 = max(points[i].first, points[j].first);
            int y2 = max(points[i].second, points[j].second);

            if (x2 - x1 + 1 < k || y2 - y1 + 1 < k) continue;

            int x = x1;
            int y = y1;
            while (x <= x2 - k + 1 && y <= y2 - k + 1) {
                int c = 0;
                for (int p = 0; p < n; p++) {
                    if (x <= points[p].first && points[p].first < x + k &&
                        y <= points[p].second && points[p].second < y + k) {
                        c++;
                    }
                }
                if (c > 0) count[c]++;
                y++;
                if (y > y2 - k + 1) {
                    y = y1;
                    x++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int x1 = points[i].first;
        int y1 = points[i].second;

        int x = x1;
        int y = y1;
        while (x <= x1 && y <= y1) {
            int c = 0;
            for (int p = 0; p < n; p++) {
                if (x <= points[p].first && points[p].first < x + k &&
                    y <= points[p].second && points[p].second < y + k) {
                    c++;
                }
            }
            if (c > 0) count[c]++;
            y++;
            if (y > y1) {
                y = y1;
                x++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (count[i]? count[i] : 0) << " ";
    }
    cout << endl;

    return 0;
}