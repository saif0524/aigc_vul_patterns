#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> B(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> B[i][j];
        }
    }

    int h, w;
    cin >> h >> w;

    vector<vector<int>> C(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> C[i][j];
        }
    }

    long long max_score = -1;
    bool found = false;

    for (int i = 0; i <= H - h; ++i) {
        for (int j = 0; j <= W - w; ++j) {
            bool match = true;
            for (int row = 0; row < h; ++row) {
                for (int col = 0; col < w; ++col) {
                    if (B[i + row][j + col] != C[row][col]) {
                        match = false;
                        break;
                    }
                }
                if (!match) break;
            }

            if (match) {
                found = true;
                long long current_score = 0;
                for (int row = 0; row < h; ++row) {
                    for (int col = 0; col < w; ++col) {
                        current_score += A[i + row][j + col];
                    }
                }
                max_score = max(max_score, current_score);
            }
        }
    }

    if (found) {
        cout << max_score << endl;
    } else {
        cout << "NA" << endl;
    }

    return 0;
}