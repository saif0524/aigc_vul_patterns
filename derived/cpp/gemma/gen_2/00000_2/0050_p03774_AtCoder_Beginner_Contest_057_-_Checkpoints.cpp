#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].first >> students[i].second;
    }

    vector<pair<int, int>> checkpoints(m);
    for (int i = 0; i < m; ++i) {
        cin >> checkpoints[i].first >> checkpoints[i].second;
    }

    for (int i = 0; i < n; ++i) {
        int best_checkpoint_index = -1;
        int min_distance = -1;

        for (int j = 0; j < m; ++j) {
            int distance = abs(students[i].first - checkpoints[j].first) + abs(students[i].second - checkpoints[j].second);

            if (best_checkpoint_index == -1 || distance < min_distance) {
                min_distance = distance;
                best_checkpoint_index = j + 1;
            } else if (distance == min_distance) {
                best_checkpoint_index = min(best_checkpoint_index, j + 1);
            }
        }

        cout << best_checkpoint_index << endl;
    }

    return 0;
}