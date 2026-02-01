#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct State {
    int city, moves, ocarina;
    State(int c, int m, int o) : city(c), moves(m), ocarina(o) {}
};

int main() {
    int N, M, E, S, T, R;
    cin >> N >> M >> E >> S >> T >> R;

    vector<vector<int>> roads(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }

    vector<tuple<int, int, int>> events;
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        events.emplace_back(a, b, c);
    }

    vector<vector<vector<int>>> dp(R + 1, vector<vector<int>>(N, vector<int>(2, INF)));
    dp[0][S][0] = 0;

    queue<State> q;
    q.emplace(S, 0, 0);

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (current.moves > R) continue;

        for (int next : roads[current.city]) {
            int next_Ocarina = current.ocarina;
            int next_Moves = current.moves + 1;
            if (next_Moves > R) {
                next_Moves = 0;
                next_Ocarina = 1;
            }

            if (dp[next_Moves][next][next_Ocarina] > next_Moves + next_Ocarina) {
                dp[next_Moves][next][next_Ocarina] = next_Moves + next_Ocarina;
                q.emplace(next, next_Moves, next_Ocarina);
            }
        }

        for (auto &[a, b, c] : events) {
            if (current.city == c) {
                int next_Ocarina = current.ocarina;
                int next_Moves = current.moves + 1;
                if (next_Moves > R) {
                    next_Moves = 0;
                    next_Ocarina = 1;
                }

                if (dp[next_Moves][b][next_Ocarina] > next_Moves + next_Ocarina) {
                    dp[next_Moves][b][next_Ocarina] = next_Moves + next_Ocarina;
                    q.emplace(b, next_Moves, next_Ocarina);
                }

                next_Moves = current.moves + 1;
                if (next_Moves > R) {
                    next_Moves = 0;
                    next_Ocarina = 1;
                }

                if (dp[next_Moves][a][next_Ocarina] > next_Moves + next_Ocarina) {
                    dp[next_Moves][a][next_Ocarina] = next_Moves + next_Ocarina;
                    q.emplace(a, next_Moves, next_Ocarina);
                }
            }
        }
    }

    int result = INF;
    for (int o = 0; o < 2; ++o) {
        result = min(result, dp[R][T][o]);
    }

    if (result == INF) {
        cout << -1;
    } else {
        cout << result;
    }

    return 0;
}