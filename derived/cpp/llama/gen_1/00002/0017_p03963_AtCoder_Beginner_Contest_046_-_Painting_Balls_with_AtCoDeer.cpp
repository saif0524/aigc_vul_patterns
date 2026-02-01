#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    if (N == 1) {
        cout << K << endl;
        return 0;
    }

    vector<long long> dp(K);
    for (int i = 0; i < K; i++) {
        dp[i] = 1;
    }

    for (int i = 1; i < N; i++) {
        vector<long long> next(K, 0);
        long long sum = 0;
        for (int j = 0; j < K; j++) {
            sum += dp[j];
        }
        for (int j = 0; j < K; j++) {
            next[j] = sum - dp[j];
        }
        swap(dp, next);
    }

    long long sum = 0;
    for (int i = 0; i < K; i++) {
        sum += dp[i];
    }
    cout << sum << endl;

    return 0;
}