#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> cupboards(n);
    for (int i = 0; i < n; ++i) {
        cin >> cupboards[i].first >> cupboards[i].second;
    }

    int min_changes = n + 1;

    // Try setting all left doors to 0
    int changes_left_0 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].first == 1) {
            changes_left_0++;
        }
    }

    // Try setting all right doors to 0
    int changes_right_0 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].second == 1) {
            changes_right_0++;
        }
    }

    min_changes = min(min_changes, changes_left_0 + changes_right_0);

    // Try setting all left doors to 1
    int changes_left_1 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].first == 0) {
            changes_left_1++;
        }
    }

    // Try setting all right doors to 1
    int changes_right_1 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].second == 0) {
            changes_right_1++;
        }
    }

    min_changes = min(min_changes, changes_left_1 + changes_right_1);

    // Try setting all left doors to 0 and all right doors to 1
    int changes_left_0_right_1 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].first == 1) {
            changes_left_0_right_1++;
        }
        if (cupboards[i].second == 0) {
            changes_left_0_right_1++;
        }
    }

    min_changes = min(min_changes, changes_left_0_right_1);
    
    // Try setting all left doors to 1 and all right doors to 0
    int changes_left_1_right_0 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].first == 0) {
            changes_left_1_right_0++;
        }
        if (cupboards[i].second == 1) {
            changes_left_1_right_0++;
        }
    }

    min_changes = min(min_changes, changes_left_1_right_0);

    cout << min_changes << endl;

    return 0;
}