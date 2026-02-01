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

    vector<int> bad_points;
    for (int j = 1; j <= 200; ++j) {
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (segments[i].first <= j && segments[i].second >= j) {
                count++;
            }
        }
        if (count > k) {
            bad_points.push_back(j);
        }
    }
    
    if (bad_points.empty()) {
        cout << 0 << endl;
        return 0;
    }

    int min_removed = n + 1;
    vector<int> best_removed;

    for (int i = 0; i < (1 << n); ++i) {
        vector<int> removed;
        vector<pair<int, int>> remaining_segments;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                removed.push_back(j + 1);
            } else {
                remaining_segments.push_back(segments[j]);
            }
        }

        bool valid = true;
        for (int j = 1; j <= 200; ++j) {
            int count = 0;
            for (int l = 0; l < remaining_segments.size(); ++l) {
                if (remaining_segments[l].first <= j && remaining_segments[l].second >= j) {
                    count++;
                }
            }
            if (count > k) {
                valid = false;
                break;
            }
        }

        if (valid) {
            if (removed.size() < min_removed) {
                min_removed = removed.size();
                best_removed = removed;
            }
        }
    }

    cout << min_removed << endl;
    for (int i = 0; i < min_removed; ++i) {
        cout << best_removed[i] << (i == min_removed - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}