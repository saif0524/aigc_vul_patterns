#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s, b, k;
    cin >> s >> b >> k;

    vector<tuple<int, int, int, int>> spaceships(s);
    for (int i = 0; i < s; ++i) {
        int x, a, f, p;
        cin >> x >> a >> f >> p;
        spaceships[i] = make_tuple(x, a, f, p);
    }

    vector<tuple<int, int, int>> bases(b);
    for (int i = 0; i < b; ++i) {
        int x, d, g;
        cin >> x >> d >> g;
        bases[i] = make_tuple(x, d, g);
    }

    vector<pair<int, int>> dependencies(k);
    for (int i = 0; i < k; ++i) {
        int s1, s2;
        cin >> s1 >> s2;
        dependencies[i] = make_pair(s1, s2);
    }

    long long max_profit = 0;

    for (int i = 0; i < (1 << s); ++i) {
        vector<bool> operated(s, false);
        for (int j = 0; j < s; ++j) {
            if ((i >> j) & 1) {
                operated[j] = true;
            }
        }

        bool valid = true;
        for (int j = 0; j < k; ++j) {
            int s1 = dependencies[j].first - 1;
            int s2 = dependencies[j].second - 1;
            if (operated[s1] && !operated[s2]) {
                valid = false;
                break;
            }
        }

        if (!valid) continue;

        long long current_profit = 0;
        
        for (int j = 0; j < s; ++j) {
            if (operated[j]) {
                int spaceship_location = get<0>(spaceships[j]);
                int spaceship_attack = get<1>(spaceships[j]);
                int spaceship_fuel = get<2>(spaceships[j]);
                int spaceship_price = get<3>(spaceships[j]);

                int best_base = -1;
                long long max_base_profit = -1e18;

                for (int l = 0; l < b; ++l) {
                    int base_location = get<0>(bases[l]);
                    int base_defense = get<1>(bases[l]);
                    int base_gold = get<2>(bases[l]);

                    if (spaceship_attack >= base_defense) {
                        vector<int> dist(n + 1, -1);
                        queue<int> q;
                        q.push(spaceship_location);
                        dist[spaceship_location] = 0;

                        while (!q.empty()) {
                            int u = q.front();
                            q.pop();

                            for (int v : adj[u]) {
                                if (dist[v] == -1) {
                                    dist[v] = dist[u] + 1;
                                    q.push(v);
                                }
                            }
                        }

                        if (dist[base_location] != -1 && spaceship_fuel >= dist[base_location]) {
                            long long profit = base_gold - spaceship_price;
                            if (profit > max_base_profit) {
                                max_base_profit = profit;
                                best_base = l;
                            }
                        }
                    }
                }

                if (best_base != -1) {
                    current_profit += max_base_profit;
                }
            }
        }

        max_profit = max(max_profit, current_profit);
    }

    cout << max_profit << endl;

    return 0;
}