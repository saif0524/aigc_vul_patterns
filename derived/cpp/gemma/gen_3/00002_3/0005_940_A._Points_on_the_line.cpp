#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());

    int min_removed = n;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> subset;
        int removed_count = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                subset.push_back(points[j]);
            } else {
                removed_count++;
            }
        }

        if (subset.empty()) {
            min_removed = min(min_removed, removed_count);
            continue;
        }

        int diameter = subset.back() - subset.front();
        if (diameter <= d) {
            min_removed = min(min_removed, removed_count);
        }
    }

    cout << min_removed << endl;

    return 0;
}