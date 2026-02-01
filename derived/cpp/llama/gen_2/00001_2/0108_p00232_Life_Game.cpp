#include <iostream>
#include <vector>

using namespace std;

int main() {
    int X, Y, Z;
    while (true) {
        cin >> X >> Y >> Z;
        if (X == 0 && Y == 0 && Z == 0) break;

        vector<int> V(X);
        for (int i = 0; i < X; i++) {
            cin >> V[i];
        }

        vector<int> N(Z), E(Z), A(Z);
        for (int i = 0; i < Z; i++) {
            cin >> N[i] >> E[i] >> A[i];
        }

        vector<double> dp(Y + 1, 0.0);
        dp[0] = 0.0;
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                int ni = i + V[j];
                if (ni <= Y) {
                    if (ni < Y) {
                        bool found = false;
                        for (int k = 0; k < Z; k++) {
                            if (N[k] == ni) {
                                found = true;
                                if (E[k] == 1) {
                                    dp[ni] += dp[i] + (double)A[k] / X;
                                } else if (E[k] == 2) {
                                    dp[ni] += (dp[i] + (double)A[k]) / X;
                                } else if (E[k] == 3) {
                                    dp[ni] += max(0.0, dp[i] - (double)A[k]) / X;
                                }
                                break;
                            }
                        }
                        if (!found) {
                            dp[ni] += dp[i] / X;
                        }
                    } else {
                        bool found = false;
                        for (int k = 0; k < Z; k++) {
                            if (N[k] == ni) {
                                found = true;
                                if (E[k] == 1) {
                                    dp[Y] += dp[i] + (double)A[k] / X;
                                } else if (E[k] == 2) {
                                    dp[Y] += (dp[i] + (double)A[k]) / X;
                                } else if (E[k] == 3) {
                                    dp[Y] += max(0.0, dp[i] - (double)A[k]) / X;
                                }
                                break;
                            }
                        }
                        if (!found) {
                            dp[Y] += dp[i] / X;
                        }
                    }
                }
            }
        }

        cout << (int)dp[Y] << endl;
    }

    return 0;
}