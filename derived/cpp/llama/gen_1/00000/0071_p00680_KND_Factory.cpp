#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int MAX_N = 100;
const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int capacity;
    int cost;
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, s, t, F;
        cin >> N >> s >> t >> F;

        vector<vector<double>> coef(N, vector<double>(N));
        vector<double> const_term(N);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> coef[i][j];
            }
            cin >> const_term[i];
        }

        // calculate temperature using Gaussian Elimination
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (coef[i][i] == 0) {
                    for (int k = 0; k < N; k++) {
                        if (coef[k][i] != 0) {
                            swap(coef[i], coef[k]);
                            swap(const_term[i], const_term[k]);
                            break;
                        }
                    }
                }
                if (coef[i][i] == 0) continue;
                double factor = coef[j][i] / coef[i][i];
                for (int k = 0; k <= N; k++) {
                    coef[j][k] -= factor * coef[i][k];
                }
            }
        }
        vector<double> temperature(N);
        for (int i = N - 1; i >= 0; i--) {
            if (coef[i][i] == 0) continue;
            double sum = 0;
            for (int j = i + 1; j < N; j++) {
                sum += coef[i][j] * temperature[j];
            }
            temperature[i] = (const_term[i] - sum) / coef[i][i];
        }

        vector<vector<Edge>> graph(N);
        for (int i = 0; i < N; i++) {
            int M;
            cin >> M;
            for (int j = 0; j < M; j++) {
                int to, capacity;
                cin >> to >> capacity;
                graph[i].push_back({to, capacity, 0});
            }
        }

        // using Bellman-Ford to find the shortest path in residual graph
        vector<pair<int, double>> pot(N, {INF, 0});
        pot[s] = {0, 0};
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (pot[j].first == INF) continue;
                for (auto& edge : graph[j]) {
                    double cost = pot[j].second + abs(temperature[j] - temperature[edge.to]);
                    if (pot[edge.to].first > pot[j].first + edge.capacity) {
                        pot[edge.to] = {pot[j].first + edge.capacity, cost};
                    }
                }
            }
        }

        if (pot[t].first == INF) {
            cout << "impossible" << endl;
            continue;
        }

        cout << fixed << setprecision(10) << pot[t].second << endl;
    }
    return 0;
}