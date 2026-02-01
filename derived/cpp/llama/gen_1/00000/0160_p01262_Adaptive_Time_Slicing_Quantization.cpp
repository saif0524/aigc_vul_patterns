#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

double quantize(const vector<double>& frame, int L) {
    double Vmin = *min_element(frame.begin(), frame.end());
    double Vmax = *max_element(frame.begin(), frame.end());
    double step = (Vmax - Vmin) / (2 * L - 1);

    double sum = 0.0;
    for (double val : frame) {
        double closest = Vmin + round((val - Vmin) / step) * step;
        sum += (val - closest) * (val - closest);
    }

    return sum;
}

void solve() {
    int N, M, L;
    cin >> N >> M >> L;

    if (N == 0 && M == 0 && L == 0) {
        return;
    }

    vector<double> seq(N);
    for (double& val : seq) {
        cin >> val;
    }

    vector<vector<double>> frames;
    vector<double> frame;
    for (int i = 0; i < N; ++i) {
        frame.push_back(seq[i]);
        if (frame.size() == 2 && M > 1) {
            frames.push_back(frame);
            frame.clear();
            M--;
        }
    }
    if (!frame.empty()) {
        frames.push_back(frame);
    }

    vector<vector<double>> dp(M + 1, vector<double>(N + 1, numeric_limits<double>::max()));
    dp[0][0] = 0.0;

    for (int i = 1; i <= M; ++i) {
        for (int j = i * 2; j <= N; ++j) {
            for (int k = j - 2; k >= i * 2 - 2; --k) {
                double error = quantize(vector<double>(seq.begin() + k, seq.begin() + j), L);
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + error);
            }
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << dp[M][N] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        solve();
    }

    return 0;
}