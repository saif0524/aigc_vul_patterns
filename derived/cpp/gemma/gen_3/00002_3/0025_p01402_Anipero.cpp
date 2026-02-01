#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int LIMIT, N, M, X;
    while (cin >> LIMIT >> N >> M >> X && LIMIT != 0) {
        vector<tuple<string, int, int>> secret_artists(N);
        for (int i = 0; i < N; ++i) {
            string name;
            int cost, satisfaction;
            cin >> name >> cost >> satisfaction;
            secret_artists[i] = make_tuple(name, cost, satisfaction);
        }

        vector<tuple<string, int, int>> standard_artists(M);
        for (int i = 0; i < M; ++i) {
            string name;
            int cost, satisfaction;
            cin >> name >> cost >> satisfaction;
            standard_artists[i] = make_tuple(name, cost, satisfaction);
        }

        int max_satisfaction = 0;

        // Iterate through all possible combinations of secret artists
        for (int i = 0; i < (1 << N); ++i) {
            int secret_cost = 0;
            int secret_satisfaction = 0;
            vector<int> selected_secret_indices;

            for (int j = 0; j < N; ++j) {
                if ((i >> j) & 1) {
                    secret_cost += get<1>(secret_artists[j]);
                    secret_satisfaction += get<2>(secret_artists[j]);
                    selected_secret_indices.push_back(j);
                }
            }

            // Check if the number of selected secret artists is within the allowed range
            int num_secret = selected_secret_indices.size();
            if (num_secret > 2 || num_secret < 0) continue;

            // Iterate through all possible combinations of standard artists
            for (int j = 0; j < (1 << M); ++j) {
                int standard_cost = 0;
                int standard_satisfaction = 0;
                int num_standard = 0;

                for (int k = 0; k < M; ++k) {
                    if ((j >> k) & 1) {
                        standard_cost += get<1>(standard_artists[k]);
                        standard_satisfaction += get<2>(standard_artists[k]);
                        num_standard++;
                    }
                }

                // Check if the number of selected standard artists meets the minimum requirement
                if (num_standard < X) continue;

                // Check if the total cost is within the limit
                if (secret_cost + standard_cost <= LIMIT) {
                    max_satisfaction = max(max_satisfaction, secret_satisfaction + standard_satisfaction);
                }
            }
        }

        cout << max_satisfaction << endl;
    }

    return 0;
}