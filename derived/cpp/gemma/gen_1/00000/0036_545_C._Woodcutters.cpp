#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> trees(n);
    for (int i = 0; i < n; ++i) {
        cin >> trees[i].first >> trees[i].second;
    }

    int max_felled = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector<pair<int, int>> occupied;
        int felled_count = 0;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                // Fell the tree
                int x = trees[j].first;
                int h = trees[j].second;

                // Try falling left
                bool can_fall_left = true;
                for (auto& segment : occupied) {
                    if (max(segment.first, x - h) <= min(segment.second, x)) {
                        can_fall_left = false;
                        break;
                    }
                }
                if (can_fall_left) {
                    occupied.push_back({x - h, x});
                    felled_count++;
                    continue;
                }

                // Try falling right
                bool can_fall_right = true;
                for (auto& segment : occupied) {
                    if (max(segment.first, x) <= min(segment.second, x + h)) {
                        can_fall_right = false;
                        break;
                    }
                }
                if (can_fall_right) {
                    occupied.push_back({x, x + h});
                    felled_count++;
                    continue;
                }
            } else {
                // Leave the tree
                occupied.push_back({trees[j].first, trees[j].first});
            }
        }
        
        max_felled = max(max_felled, felled_count);
    }

    cout << max_felled << endl;

    return 0;
}