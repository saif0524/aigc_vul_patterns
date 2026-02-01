#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> M(N);
    for (auto &m : M) cin >> m;

    vector<int> rowOccupied(K, 0);

    for (auto &m : M) {
        int bestX = -1, bestYl = -1, bestYr = -1;
        long long bestScore = LLONG_MAX;

        for (int x = 0; x < K; ++x) {
            if (K - rowOccupied[x] < m) continue;
            for (int yl = 0; yl <= K - m; ++yl) {
                bool canPlace = true;
                for (int y = yl; y < yl + m; ++y) {
                    if ((rowOccupied[x] >> y) & 1) {
                        canPlace = false;
                        break;
                    }
                }
                if (canPlace) {
                    int yr = yl + m - 1;
                    int center = K / 2;
                    long long score = 0;
                    for (int y = yl; y <= yr; ++y) {
                        score += abs(center - y);
                    }
                    if (score < bestScore || (score == bestScore && (x < bestX || (x == bestX && yl < bestYl)))) {
                        bestScore = score;
                        bestX = x;
                        bestYl = yl;
                        bestYr = yr;
                    }
                }
            }
        }

        if (bestX == -1) {
            cout << "-1\n";
        } else {
            cout << bestX + 1 << " " << bestYl + 1 << " " << bestYr + 1 << "\n";
            for (int y = bestYl; y <= bestYr; ++y) {
                rowOccupied[bestX] |= (1 << y);
            }
        }
    }

    return 0;
}