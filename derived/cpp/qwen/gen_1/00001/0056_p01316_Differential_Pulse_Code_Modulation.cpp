#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M && (N || M)) {
        vector<int> C(M);
        for (int i = 0; i < M; ++i) cin >> C[i];
        vector<int> x(N);
        for (int i = 0; i < N; ++i) cin >> x[i];
        
        vector<int> dp(256, INT_MAX);
        dp[128] = 0;
        
        for (int i = 0; i < N; ++i) {
            vector<int> ndp(256, INT_MAX);
            for (int y = 0; y <= 255; ++y) {
                if (dp[y] == INT_MAX) continue;
                for (int c : C) {
                    int ny = y + c;
                    if (ny < 0) ny = 0;
                    if (ny > 255) ny = 255;
                    ndp[ny] = min(ndp[ny], dp[y] + (x[i] - ny) * (x[i] - ny));
                }
            }
            dp = ndp;
        }
        
        int result = *min_element(dp.begin(), dp.end());
        cout << result << endl;
    }
    return 0;
}