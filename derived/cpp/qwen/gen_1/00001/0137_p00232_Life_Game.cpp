#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        if (X == 0 && Y == 0 && Z == 0) break;
        
        vector<int> roulette(X);
        for (int i = 0; i < X; ++i) {
            cin >> roulette[i];
        }
        
        vector<vector<int>> events(Y + 1, vector<int>(3));
        for (int i = 0; i < Z; ++i) {
            int N, E, A;
            cin >> N >> E >> A;
            events[N][0] = E;
            events[N][1] = A;
        }
        
        vector<double> dp(Y + 100, 0.0);
        dp[0] = 1.0;
        
        for (int i = 0; i <= Y; ++i) {
            if (dp[i] == 0.0) continue;
            for (int j = 0; j < X; ++j) {
                int next = i + roulette[j];
                if (next >= Y) {
                    dp[Y] += dp[i] / X;
                } else {
                    int E = events[next][0];
                    int A = events[next][1];
                    if (E == 1) {
                        if (next + A >= Y) {
                            dp[Y] += dp[i] / X;
                        } else {
                            dp[next + A] += dp[i] / X;
                        }
                    } else if (E == 2) {
                        dp[next] += dp[i] / X;
                        dp[next] += dp[i] / X * A;
                    } else if (E == 3) {
                        dp[next] += dp[i] / X;
                        dp[next] -= dp[i] / X * A;
                        if (dp[next] < 0.0) dp[next] = 0.0;
                    }
                }
            }
        }
        
        int expected_value = 0;
        for (int i = Y + 1; i < Y + 100; ++i) {
            expected_value += (i - Y) * dp[i];
        }
        cout << expected_value << endl;
    }
    return 0;
}