#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N, R;
    cin >> N >> R;
    vector<int> fast(N), slow(N);
    vector<double> prob(N);
    for (int i = 0; i < N; i++) {
        cin >> fast[i] >> slow[i] >> prob[i];
        prob[i] = prob[i] / 100.0;
    }

    vector<double> expect(N + 1, 0.0);
    for (int i = 1; i <= N; i++) {
        vector<double> dp(R + 1, 1e18);
        dp[0] = 0.0;
        for (int j = 1; j <= i; j++) {
            vector<double> tmp(R + 1, 0.0);
            for (int k = 0; k <= R; k++) {
                if (dp[k] >= 1e17) continue;
                if (k + fast[j - 1] <= R) {
                    tmp[k + fast[j - 1]] += dp[k] * prob[j - 1];
                }
                if (k + slow[j - 1] <= R) {
                    tmp[k + slow[j - 1]] += dp[k] * (1.0 - prob[j - 1]);
                }
            }
            for (int k = 1; k <= R; k++) {
                tmp[k] += tmp[k - 1];
            }
            for (int k = 0; k <= R; k++) {
                dp[k] = min(dp[k], tmp[k]);
            }
        }
        double p = 1.0;
        for (int j = 1; j <= i; j++) {
            p *= prob[j - 1];
        }
        expect[i] = dp[R] * p;
        for (int j = 1; j < i; j++) {
            double q = 1.0;
            for (int k = j; k <= i; k++) {
                q *= prob[k - 1];
            }
            expect[i] += expect[j] * (1.0 - q);
        }
    }

    printf("%.9f\n", expect[N]);

    return 0;
}