#include <bits/stdc++.h>
using namespace std;

struct Artist {
    string name;
    int cost, satisfaction;
};

int main() {
    while (true) {
        int LIMIT, N, M, X;
        cin >> LIMIT >> N >> M >> X;
        if (LIMIT == 0 && N == 0 && M == 0 && X == 0) break;

        vector<Artist> secret_artists(N);
        for (auto &a : secret_artists) cin >> a.name >> a.cost >> a.satisfaction;

        vector<Artist> standard_artists(M);
        for (auto &a : standard_artists) cin >> a.name >> a.cost >> a.satisfaction;

        int best_satisfaction = 0;

        // Consider choosing 1 or 2 secret artists
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                int current_cost = secret_artists[i].cost + secret_artists[j].cost;
                int current_satisfaction = secret_artists[i].satisfaction + secret_artists[j].satisfaction;

                vector<int> dp(LIMIT + 1, 0);

                // process secret artists i and j
                for (const auto &artist : {secret_artists[i], secret_artists[j]}) {
                    for (int money = LIMIT; money >= artist.cost; --money) {
                        dp[money] = max(dp[money], dp[money - artist.cost] + artist.satisfaction);
                    }
                }

                // process standard artists
                for (const auto &artist : standard_artists) {
                    for (int money = LIMIT; money >= artist.cost; --money) {
                        dp[money] = max(dp[money], dp[money - artist.cost] + artist.satisfaction);
                    }
                }

                for (int money = LIMIT; money >= current_cost; --money) {
                    dp[money] = max(dp[money], dp[money - current_cost] + current_satisfaction);
                }

                // Check the best combination with at least X standard artists
                int count = 0;
                for (int money = 0; money <= LIMIT; ++money) {
                    if (dp[money] > 0) count += 1;
                }

                for (int money = 0; money <= LIMIT; ++money) {
                    if (dp[money] > 0 && count >= X) {
                        best_satisfaction = max(best_satisfaction, dp[money]);
                    }
                }
            }
        }

        // Consider choosing only 1 secret artist
        for (int i = 0; i < N; ++i) {
            int current_cost = secret_artists[i].cost;
            int current_satisfaction = secret_artists[i].satisfaction;

            vector<int> dp(LIMIT + 1, 0);

            // process secret artist i
            for (const auto &artist : {secret_artists[i]}) {
                for (int money = LIMIT; money >= artist.cost; --money) {
                    dp[money] = max(dp[money], dp[money - artist.cost] + artist.satisfaction);
                }
            }

            // process standard artists
            for (const auto &artist : standard_artists) {
                for (int money = LIMIT; money >= artist.cost; --money) {
                    dp[money] = max(dp[money], dp[money - artist.cost] + artist.satisfaction);
                }
            }

            for (int money = LIMIT; money >= current_cost; --money) {
                dp[money] = max(dp[money], dp[money - current_cost] + current_satisfaction);
            }

            // Check the best combination with at least X standard artists
            int count = 0;
            for (int money = 0; money <= LIMIT; ++money) {
                if (dp[money] > 0) count += 1;
            }

            for (int money = 0; money <= LIMIT; ++money) {
                if (dp[money] > 0 && count >= X) {
                    best_satisfaction = max(best_satisfaction, dp[money]);
                }
            }
        }

        // Consider choosing no secret artists
        vector<int> dp(LIMIT + 1, 0);

        // process standard artists
        for (const auto &artist : standard_artists) {
            for (int money = LIMIT; money >= artist.cost; --money) {
                dp[money] = max(dp[money], dp[money - artist.cost] + artist.satisfaction);
            }
        }

        // Check the best combination with at least X standard artists
        int count = 0;
        for (int money = 0; money <= LIMIT; ++money) {
            if (dp[money] > 0) count += 1;
        }

        for (int money = 0; money <= LIMIT; ++money) {
            if (dp[money] > 0 && count >= X) {
                best_satisfaction = max(best_satisfaction, dp[money]);
            }
        }

        cout << best_satisfaction << '\n';
    }
}