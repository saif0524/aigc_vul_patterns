#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int students[N][2], checkpoints[M][2];

    for (int i = 0; i < N; i++) {
        cin >> students[i][0] >> students[i][1];
    }

    for (int i = 0; i < M; i++) {
        cin >> checkpoints[i][0] >> checkpoints[i][1];
    }

    for (int i = 0; i < N; i++) {
        int minDist = abs(students[i][0] - checkpoints[0][0]) + abs(students[i][1] - checkpoints[0][1]);
        int minIndex = 1;

        for (int j = 1; j < M; j++) {
            int dist = abs(students[i][0] - checkpoints[j][0]) + abs(students[i][1] - checkpoints[j][1]);

            if (dist < minDist) {
                minDist = dist;
                minIndex = j + 1;
            }
        }

        cout << minIndex << endl;
    }

    return 0;
}