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

    vector<int> remove_indices;
    int min_removed = n + 1;

    for (int i = 0; i < (1 << n); ++i) {
        vector<pair<int, int>> remaining_segments;
        vector<int> current_remove_indices;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                remaining_segments.push_back(segments[j]);
            } else {
                current_remove_indices.push_back(j + 1);
            }
        }

        bool bad_point_exists = false;
        for (int point = 1; point <= 200; ++point) {
            int count = 0;
            for (const auto& segment : remaining_segments) {
                if (point >= segment.first && point <= segment.second) {
                    count++;
                }
            }
            if (count > k) {
                bad_point_exists = true;
                break;
            }
        }

        if (!bad_point_exists) {
            if (current_remove_indices.size() < min_removed) {
                min_removed = current_remove_indices.size();
                remove_indices = current_remove_indices;
            }
        }
    }

    cout << min_removed << endl;
    for (int i = 0; i < min_removed; ++i) {
        cout << remove_indices[i] << (i == min_removed - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}