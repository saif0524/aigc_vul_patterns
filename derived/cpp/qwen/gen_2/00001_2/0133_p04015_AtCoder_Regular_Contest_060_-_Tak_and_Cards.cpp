#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, A;
    cin >> N >> A;
    vector<int> x(N);
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
    }

    vector<vector<long long>> dp(N + 1, vector<long long>(N * 50 + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= N; ++i) {
        for (int sum = 0; sum <= N * 50; ++sum) {
            dp[i][sum] += dp[i - 1][sum];
            if (sum >= x[i - 1]) {
                dp[i][sum] += dp[i - 1][sum - x[i - 1]];
            }
        }
    }

    long long result = 0;
    for (int count = 1; count <= N; ++count) {
        int target_sum = count * A;
        if (target_sum <= N * 50) {
            result += dp[N][target_sum];
        }
    }

    cout << result << endl;
    return 0;
}