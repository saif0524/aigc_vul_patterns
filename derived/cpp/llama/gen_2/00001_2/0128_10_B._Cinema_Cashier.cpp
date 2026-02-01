#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> M(N);
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }

    vector<vector<bool>> seats(K, vector<bool>(K, true));

    for (int i = 0; i < N; i++) {
        int best_x = -1, best_yl = -1, best_yr = -1;
        int best_distance = 1e9;

        for (int x = 0; x < K; x++) {
            for (int yl = 0; yl <= K - M[i]; yl++) {
                int yr = yl + M[i] - 1;
                bool available = true;
                for (int y = yl; y <= yr; y++) {
                    if (!seats[x][y]) {
                        available = false;
                        break;
                    }
                }

                if (available) {
                    int distance = 0;
                    for (int y = yl; y <= yr; y++) {
                        distance += (x - (K - 1) / 2) * (x - (K - 1) / 2) + (y - (K - 1) / 2) * (y - (K - 1) / 2);
                    }

                    if (distance < best_distance) {
                        best_distance = distance;
                        best_x = x;
                        best_yl = yl;
                        best_yr = yr;
                    } else if (distance == best_distance) {
                        if (x < best_x) {
                            best_x = x;
                            best_yl = yl;
                            best_yr = yr;
                        } else if (x == best_x && yl < best_yl) {
                            best_x = x;
                            best_yl = yl;
                            best_yr = yr;
                        }
                    }
                }
            }
        }

        if (best_x == -1) {
            cout << "-1" << endl;
        } else {
            cout << best_x + 1 << " " << best_yl + 1 << " " << best_yr + 1 << endl;
            for (int y = best_yl; y <= best_yr; y++) {
                seats[best_x][y] = false;
            }
        }
    }

    return 0;
}