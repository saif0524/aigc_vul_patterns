#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int planet;
        double new_p;
        cin >> planet >> new_p;
        p[planet] = new_p;

        double expected_components = 0.0;
        
        
        for (int j = 0; j < (1 << n); ++j) {
            vector<bool> fallen(n, false);
            double probability = 1.0;

            for (int k = 0; k < n; ++k) {
                if ((j >> k) & 1) {
                    fallen[k] = true;
                    probability *= p[k];
                } else {
                    probability *= (1.0 - p[k]);
                }
            }

            vector<bool> visited(n, false);
            int num_components = 0;

            for (int k = 0; k < n; ++k) {
                if (!fallen[k] && !visited[k]) {
                    num_components++;
                    vector<int> q_nodes;
                    q_nodes.push_back(k);
                    visited[k] = true;

                    int head = 0;
                    while (head < q_nodes.size()) {
                        int u = q_nodes[head++];
                        for (int v : adj[u]) {
                            if (!fallen[v] && !visited[v]) {
                                visited[v] = true;
                                q_nodes.push_back(v);
                            }
                        }
                    }
                }
            }
            expected_components += probability * num_components;
        }
        
        
        cout << fixed << setprecision(5) << expected_components << endl;
    }

    return 0;
}