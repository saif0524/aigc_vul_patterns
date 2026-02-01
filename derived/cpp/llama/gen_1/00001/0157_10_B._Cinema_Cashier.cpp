#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    vector<int> M(N);
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    vector<vector<bool>> occupied(K, vector<bool>(K, false));

    for (int i = 0; i < N; i++) {
        int best_row = -1;
        int best_col = -1;
        double best_distance = numeric_limits<double>::max();

        for (int row = 0; row < K; row++) {
            for (int col = 0; col <= K - M[i]; col++) {
                bool is_occupied = false;
                for (int j = 0; j < M[i]; j++) {
                    if (occupied[row][col + j]) {
                        is_occupied = true;
                        break;
                    }
                }
                if (is_occupied) {
                    continue;
                }

                double distance = 0;
                for (int j = 0; j < M[i]; j++) {
                    distance += sqrt(pow(row - (K - 1) / 2.0, 2) + pow(col + j - (K - 1) / 2.0, 2));
                }

                if (distance < best_distance ||
                    (distance == best_distance && (row < (occupied[best_row][best_col] ? (K - 1) / 2.0 : best_row)))) {
                    best_row = row;
                    best_col = col;
                    best_distance = distance;
                } else if (distance == best_distance && row == best_row && col < best_col) {
                    best_row = row;
                    best_col = col;
                }
            }
        }

        if (best_row == -1) {
            cout << -1 << '\n';
        } else {
            cout << best_row + 1 << ' ' << best_col + 1 << ' ' << best_col + M[i] << '\n';
            for (int j = 0; j < M[i]; j++) {
                occupied[best_row][best_col + j] = true;
            }
        }
    }
    return 0;
}