#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> a[i][j];
        }
    }

    int result = 0;
    for (int mask = 0; mask < (1 << h); ++mask) {
        int sum = 0;
        for (int j = 0; j < w; ++j) {
            int maxVal = 0;
            for (int i = 0; i < h; ++i) {
                if ((mask & (1 << i)) != 0) {
                    maxVal = max(maxVal, a[i][j]);
                }
            }
            sum += maxVal;
        }
        result = max(result, sum);
    }

    cout << result << "\n";

    return 0;
}