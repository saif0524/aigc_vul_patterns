#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].first >> segments[i].second;
    }

    vector<int> removed_segments;
    int min_removed = n + 1;

    for (int i = 0; i < (1 << n); ++i) {
        vector<int> current_removed_segments;
        vector<pair<int, int>> current_segments;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                current_removed_segments.push_back(j + 1);
            } else {
                current_segments.push_back(segments[j]);
            }
        }

        bool bad_point_exists = false;
        for (int point = 1; point <= 200; ++point) {
            int covered_count = 0;
            for (auto& segment : current_segments) {
                if (segment.first <= point && point <= segment.second) {
                    covered_count++;
                }
            }
            if (covered_count > k) {
                bad_point_exists = true;
                break;
            }
        }

        if (!bad_point_exists) {
            if (current_removed_segments.size() < min_removed) {
                min_removed = current_removed_segments.size();
                removed_segments = current_removed_segments;
            }
        }
    }

    cout << min_removed << endl;
    for (int i = 0; i < removed_segments.size(); ++i) {
        cout << removed_segments[i] << (i == removed_segments.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}