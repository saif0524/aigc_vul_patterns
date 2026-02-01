#include <bits/stdc++.h>
using namespace std;

const int MAX_Y = 55;

double dp[MAX_Y];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int X, Y, Z;
        cin >> X >> Y >> Z;

        if (X == 0 && Y == 0 && Z == 0) break;

        vector<int> V(X);
        for (int i = 0; i < X; i++) cin >> V[i];

        vector<tuple<int, int, int>> events(Z);
        for (int i = 0; i < Z; i++) {
            int N, E, A;
            cin >> N >> E >> A;
            events[i] = {N, E, A};
        }

        sort(events.begin(), events.end());

        fill(dp, dp + Y + 1, 0.0);

        dp[0] = 0.0;

        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                int next = min(i + V[j], Y);

                bool eventFound = false;
                for (const auto& event : events) {
                    int N, E, A;
                    tie(N, E, A) = event;
                    if (N == next) {
                        if (E == 1) next += A;
                        else if (E == 2) dp[next] += A;
                        else if (E == 3) dp[next] -= A;

                        if (dp[next] < 0) dp[next] = 0;
                        eventFound = true;
                        break;
                    }
                }

                if (!eventFound) {
                    dp[next] += dp[i];
                }
            }

            for (int j = 0; j < X; j++) {
                dp[i] = 0.0;
            }
        }

        double answer = 0.0;
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                int next = min(i + V[j], Y);
                answer += dp[next] / (double)X;
            }
        }

        cout << (int)answer << '\n';
    }

    return 0;
}