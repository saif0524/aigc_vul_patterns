#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> students, checkpoints;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        students.emplace_back(x, y);
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        checkpoints.emplace_back(x, y);
    }

    for (int i = 0; i < N; i++) {
        int min_distance = INT_MAX;
        int nearest_checkpoint = -1;

        for (int j = 0; j < M; j++) {
            int distance = abs(students[i].first - checkpoints[j].first) + abs(students[i].second - checkpoints[j].second);

            if (distance < min_distance) {
                min_distance = distance;
                nearest_checkpoint = j + 1;
            }
        }

        cout << nearest_checkpoint << endl;
    }

    return 0;
}