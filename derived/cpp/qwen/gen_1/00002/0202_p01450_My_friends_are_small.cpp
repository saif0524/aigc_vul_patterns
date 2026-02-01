#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> weights(N);
    for (int i = 0; i < N; ++i) {
        cin >> weights[i];
    }

    vector<int> dp(W + 1, 0);
    dp[0] = 1;

    for (int w : weights) {
        for (int j = W; j >= w; --j) {
            dp[j] = (dp[j] + dp[j - w]) % MOD;
        }
    }

    int result = 0;
    for (int i = 0; i <= W; ++i) {
        result = (result + dp[i]) % MOD;
    }

    cout << result << endl;
    return 0;
}