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

    vector<bool> dp(W + 1, false);
    dp[0] = true;

    for (int weight : weights) {
        for (int j = W; j >= weight; --j) {
            if (dp[j - weight]) {
                dp[j] = true;
            }
        }
    }

    int count = 0;
    for (int j = 0; j <= W; ++j) {
        if (dp[j]) {
            count = (count + 1) % MOD;
        }
    }

    cout << count << endl;
    return 0;
}