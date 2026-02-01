#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 55;

int X, Y, Z;
int V[5];
int N[MAX_N], E[MAX_N], A[MAX_N];
int dp[MAX_N];

void solve() {
    cin >> X >> Y >> Z;

    for (int i = 0; i < X; i++) {
        cin >> V[i];
    }

    for (int i = 0; i < Z; i++) {
        cin >> N[i] >> E[i] >> A[i];
    }

    fill(dp, dp + MAX_N, 0);
    dp[0] = 0;

    for (int i = 0; i < Y; i++) {
        for (int j = 0; j < X; j++) {
            int nxt = i + V[j];
            if (nxt >= Y) {
                continue;
            }

            bool flag = false;
            for (int k = 0; k < Z; k++) {
                if (N[k] == nxt) {
                    flag = true;
                    if (E[k] == 1) {
                        nxt += A[k];
                    } else if (E[k] == 2) {
                        dp[nxt] += A[k];
                    } else {
                        dp[nxt] -= A[k];
                    }
                    dp[nxt] = max(dp[nxt], 0);
                    break;
                }
            }

            if (!flag) {
                dp[nxt] += dp[i];
            }
        }

        for (int j = 0; j < X; j++) {
            dp[i] = 0;
        }
    }

    long long ans = 0;
    for (int i = Y; i < MAX_N; i++) {
        ans += dp[i];
    }

    for (int i = 0; i < Z; i++) {
        if (N[i] >= Y) {
            if (E[i] == 2) {
                ans += A[i];
            } else if (E[i] == 3) {
                ans -= A[i];
            }
        }
    }

    ans = (ans * X) / X;
    cout << ans << endl;
}

int main() {
    while (true) {
        solve();
        if (X == 0 && Y == 0 && Z == 0) {
            break;
        }
    }
    return 0;
}