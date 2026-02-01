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

        double expected_kingdoms = 0.0;
        
        vector<bool> visited(n, false);
        int num_kingdoms = 0;

        for (int start_node = 0; start_node < n; ++start_node) {
            if (!visited[start_node]) {
                num_kingdoms++;
                vector<int> q_nodes;
                q_nodes.push_back(start_node);
                visited[start_node] = true;
                
                int head = 0;
                while (head < q_nodes.size()) {
                    int u = q_nodes[head++];
                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q_nodes.push_back(v);
                        }
                    }
                }
            }
        }

        
        vector<double> prob(1 << n, 0.0);
        prob[0] = 1.0;

        for (int j = 0; j < n; ++j) {
            for (int k = (1 << n) - 1; k >= 0; --k) {
                if (prob[k] > 0.0) {
                    if (!(k & (1 << j))) {
                        prob[k | (1 << j)] += prob[k] * p[j];
                    }
                }
            }
        }

        
        double total_expected_kingdoms = 0.0;
        for (int k = 0; k < (1 << n); ++k) {
            if (prob[k] > 0.0) {
                
                vector<bool> fallen(n, false);
                for (int j = 0; j < n; ++j) {
                    if (k & (1 << j)) {
                        fallen[j] = true;
                    }
                }
                
                vector<bool> visited_for_prob(n, false);
                int kingdoms_for_prob = 0;

                for (int start_node = 0; start_node < n; ++start_node) {
                    if (!fallen[start_node] && !visited_for_prob[start_node]) {
                        kingdoms_for_prob++;
                        vector<int> q_nodes_prob;
                        q_nodes_prob.push_back(start_node);
                        visited_for_prob[start_node] = true;
                        
                        int head_prob = 0;
                        while (head_prob < q_nodes_prob.size()) {
                            int u = q_nodes_prob[head_prob++];
                            for (int v : adj[u]) {
                                if (!fallen[v] && !visited_for_prob[v]) {
                                    visited_for_prob[v] = true;
                                    q_nodes_prob.push_back(v);
                                }
                            }
                        }
                    }
                }

                total_expected_kingdoms += kingdoms_for_prob * prob[k];
            }
        }
        
        
        cout << fixed << setprecision(5) << total_expected_kingdoms << endl;
    }

    return 0;
}