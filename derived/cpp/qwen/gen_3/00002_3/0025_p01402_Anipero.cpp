#include <bits/stdc++.h>
using namespace std;

struct Artist {
    string name;
    int cost;
    int satisfaction;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int LIMIT, N, M, X;
        cin >> LIMIT >> N >> M >> X;
        if (LIMIT == 0 && N == 0 && M == 0 && X == 0) break;

        vector<Artist> secret_artists(N), standard_artists(M);
        for (int i = 0; i < N; ++i) {
            cin >> secret_artists[i].name >> secret_artists[i].cost >> secret_artists[i].satisfaction;
        }
        for (int i = 0; i < M; ++i) {
            cin >> standard_artists[i].name >> standard_artists[i].cost >> standard_artists[i].satisfaction;
        }

        int max_satisfaction = 0;

        // Select 1 or 2 secret artists
        for (int sec_count = 1; sec_count <= 2; ++sec_count) {
            if (sec_count == 2 && N < 2) continue;

            vector<bool> sec_combination(N, false);
            for (int i = 0; i < sec_count; ++i) sec_combination[N - i - 1] = true;

            do {
                int current_cost = 0;
                int current_satisfaction = 0;

                // Calculate cost and satisfaction for selected secret artists
                for (int i = 0; i < N; ++i) {
                    if (sec_combination[i]) {
                        current_cost += secret_artists[i].cost;
                        current_satisfaction += secret_artists[i].satisfaction;
                    }
                }

                // Select at least X standard artists
                vector<bool> std_combination(M, false);
                for (int i = 0; i < X; ++i) std_combination[M - i - 1] = true;

                do {
                    int std_cost = 0;
                    int std_satisfaction = 0;

                    // Calculate cost and satisfaction for selected standard artists
                    for (int i = 0; i < M; ++i) {
                        if (std_combination[i]) {
                            std_cost += standard_artists[i].cost;
                            std_satisfaction += standard_artists[i].satisfaction;
                        }
                    }

                    int total_cost = current_cost + std_cost;
                    int total_satisfaction = current_satisfaction + std_satisfaction;

                    if (total_cost <= LIMIT) {
                        max_satisfaction = max(max_satisfaction, total_satisfaction);
                    }

                } while (next_permutation(std_combination.begin(), std_combination.end()));

            } while (next_permutation(sec_combination.begin(), sec_combination.end()));
        }

        cout << max_satisfaction << "\n";
    }

    return 0;
}