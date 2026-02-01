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

    // Try making all left doors 0
    int changes_left_0 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].first == 1) {
            changes_left_0++;
        }
    }

    // Try making all right doors 0
    int changes_right_0 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].second == 1) {
            changes_right_0++;
        }
    }

    min_changes = min({min_changes, changes_left_0 + changes_right_0});

    // Try making all left doors 1
    int changes_left_1 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].first == 0) {
            changes_left_1++;
        }
    }

    // Try making all right doors 1
    int changes_right_1 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].second == 0) {
            changes_right_1++;
        }
    }
    
    min_changes = min({min_changes, changes_left_1 + changes_right_1});
    

    // Try making all left doors 0 and all right doors 1
    int changes_left_0_right_1 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].first == 1) {
            changes_left_0_right_1++;
        }
        if (cupboards[i].second == 0) {
            changes_left_0_right_1++;
        }
    }
    min_changes = min({min_changes, changes_left_0_right_1});

    // Try making all left doors 1 and all right doors 0
    int changes_left_1_right_0 = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].first == 0) {
            changes_left_1_right_0++;
        }
        if (cupboards[i].second == 1) {
            changes_left_1_right_0++;
        }
    }
    min_changes = min({min_changes, changes_left_1_right_0});

    
    int left_0_count = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].first == 0) {
            left_0_count++;
        }
    }
    int left_1_count = n - left_0_count;

    int right_0_count = 0;
    for (int i = 0; i < n; ++i) {
        if (cupboards[i].second == 0) {
            right_0_count++;
        }
    }
    int right_1_count = n - right_0_count;
    
    if (left_0_count >= right_0_count) {
        min_changes = min(min_changes, right_0_count + (n - left_0_count));
    } else {
        min_changes = min(min_changes, left_0_count + (n - right_0_count));
    }

    
    if (left_1_count >= right_1_count) {
        min_changes = min(min_changes, right_1_count + (n - left_1_count));
    } else {
        min_changes = min(min_changes, left_1_count + (n - right_1_count));
    }

    
    

    cout << min_changes << endl;

    return 0;
}