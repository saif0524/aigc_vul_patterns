#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int limit, n, m, x;
    while (cin >> limit >> n >> m >> x && limit != 0 && n != 0 && m != 0 && x != 0) {
        vector<tuple<string, int, int>> secret_artists(n);
        for (int i = 0; i < n; ++i) {
            string name;
            int cost, satisfaction;
            cin >> name >> cost >> satisfaction;
            secret_artists[i] = make_tuple(name, cost, satisfaction);
        }

        vector<tuple<string, int, int>> standard_artists(m);
        for (int i = 0; i < m; ++i) {
            string name;
            int cost, satisfaction;
            cin >> name >> cost >> satisfaction;
            standard_artists[i] = make_tuple(name, cost, satisfaction);
        }

        int max_satisfaction = 0;

        // Iterate through all possible combinations of secret artists (0, 1, or 2)
        for (int i = 0; i < (1 << n); ++i) {
            if (__builtin_popcount(i) > 2) continue;

            int secret_cost = 0;
            int secret_satisfaction = 0;
            vector<tuple<string, int, int>> selected_secret_artists;

            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    secret_cost += get<1>(secret_artists[j]);
                    secret_satisfaction += get<2>(secret_artists[j]);
                    selected_secret_artists.push_back(secret_artists[j]);
                }
            }

            // Iterate through all possible combinations of standard artists (X or more)
            for (int j = 0; j < (1 << m); ++j) {
                if (__builtin_popcount(j) < x) continue;

                int standard_cost = 0;
                int standard_satisfaction = 0;
                vector<tuple<string, int, int>> selected_standard_artists;

                for (int k = 0; k < m; ++k) {
                    if ((j >> k) & 1) {
                        standard_cost += get<1>(standard_artists[k]);
                        standard_satisfaction += get<2>(standard_artists[k]);
                        selected_standard_artists.push_back(standard_artists[k]);
                    }
                }

                // Check if the total cost is within the limit
                if (secret_cost + standard_cost <= limit) {
                    max_satisfaction = max(max_satisfaction, secret_satisfaction + standard_satisfaction);
                }
            }
        }

        cout << max_satisfaction << endl;
    }

    return 0;
}