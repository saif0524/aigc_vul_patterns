#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> students(N);
    for (int i = 0; i < N; i++) {
        cin >> students[i].first >> students[i].second;
    }

    vector<pair<int, int>> checkpoints(M);
    for (int i = 0; i < M; i++) {
        cin >> checkpoints[i].first >> checkpoints[i].second;
    }

    for (int i = 0; i < N; i++) {
        int minDistance = INT_MAX;
        int nearestCheckpoint = -1;

        for (int j = 0; j < M; j++) {
            int distance = abs(students[i].first - checkpoints[j].first) + abs(students[i].second - checkpoints[j].second);

            if (distance < minDistance) {
                minDistance = distance;
                nearestCheckpoint = j + 1;
            }
        }

        cout << nearestCheckpoint << endl;
    }

    return 0;
}