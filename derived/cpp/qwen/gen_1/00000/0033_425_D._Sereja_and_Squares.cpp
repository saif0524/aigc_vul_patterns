#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    unordered_set<long long> pointSet;

    for (auto& [x, y] : points) {
        cin >> x >> y;
        pointSet.insert(static_cast<long long>(x) * 100001 + y);
    }

    long long count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto [x1, y1] = points[i];
            auto [x2, y2] = points[j];

            if (x1 != x2 && y1 != y2) {
                if (pointSet.count(static_cast<long long>(x1) * 100001 + y2) &&
                    pointSet.count(static_cast<long long>(x2) * 100001 + y1)) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
}