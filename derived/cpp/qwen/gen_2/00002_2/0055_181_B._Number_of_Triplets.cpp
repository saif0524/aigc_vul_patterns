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

    long long count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int x1 = points[i].first;
                int y1 = points[i].second;
                int x2 = points[j].first;
                int y2 = points[j].second;
                int x3 = points[k].first;
                int y3 = points[k].second;

                if ((x1 + x3) == 2 * x2 && (y1 + y3) == 2 * y2) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}