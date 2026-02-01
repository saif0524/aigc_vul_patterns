#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    int N, S;
    cin >> N >> S;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(S + 1, 0));
    for (int i = 0; i <= N; i++) {
        dp[i][0] = 1;
    }

    long long ans = 0;
    for (int R = 1; R <= N; R++) {
        for (int L = R; L >= 1; L--) {
            for (int s = 0; s <= S; s++) {
                if (s + A[L - 1] <= S) {
                    dp[L][s + A[L - 1]] = (dp[L][s + A[L - 1]] + dp[L + 1][s]) % MOD;
                }
            }
            ans = (ans + dp[L][S]) % MOD;
        }
        for (int s = 0; s <= S; s++) {
            dp[R + 1][s] = (dp[R + 1][s] + dp[R][s]) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}