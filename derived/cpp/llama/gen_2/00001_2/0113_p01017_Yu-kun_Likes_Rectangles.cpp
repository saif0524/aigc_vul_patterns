#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int H, W, h, w;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> B(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> B[i][j];
        }
    }
    cin >> h >> w;
    vector<vector<int>> C(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> C[i][j];
        }
    }

    int maxScore = -200 * 50 * 50;
    bool found = false;
    for (int i = 0; i <= H - h; i++) {
        for (int j = 0; j <= W - w; j++) {
            bool match = true;
            for (int k = 0; k < h; k++) {
                for (int l = 0; l < w; l++) {
                    if (B[i + k][j + l] != C[k][l]) {
                        match = false;
                        break;
                    }
                }
                if (!match) break;
            }
            if (match) {
                int score = 0;
                for (int k = 0; k < h; k++) {
                    for (int l = 0; l < w; l++) {
                        score += A[i + k][j + l];
                    }
                }
                maxScore = max(maxScore, score);
                found = true;
            }
        }
    }

    if (found) {
        cout << maxScore << endl;
    } else {
        cout << "NA" << endl;
    }
    return 0;
}