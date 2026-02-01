#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> A[i][j];
    vector<vector<int>> B(H, vector<int>(W));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) cin >> B[i][j];
    int h, w;
    cin >> h >> w;
    vector<vector<int>> C(h, vector<int>(w));
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) cin >> C[i][j];
    
    int max_score = INT_MIN;
    bool found = false;
    for (int i = 0; i <= H - h; ++i) {
        for (int j = 0; j <= W - w; ++j) {
            bool match = true;
            int current_score = 0;
            for (int x = 0; x < h && match; ++x) {
                for (int y = 0; y < w && match; ++y) {
                    if (B[i + x][j + y] != C[x][y]) {
                        match = false;
                    } else {
                        current_score += A[i + x][j + y];
                    }
                }
            }
            if (match) {
                found = true;
                max_score = max(max_score, current_score);
            }
        }
    }
    if (found) {
        cout << max_score;
    } else {
        cout << "NA";
    }
}