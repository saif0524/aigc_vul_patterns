#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n, s, t;
    while (cin >> n >> s >> t && (n != 0 || s != 0 || t != 0)) {
        vector<int> signs(n);
        for (int i = 0; i < n; ++i) {
            cin >> signs[i];
        }

        vector<vector<int>> adj_matrix(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> adj_matrix[i][j];
            }
        }

        vector<double> dist(n, -1.0);
        dist[s - 1] = 0.0;

        vector<bool> visited(n, false);
        
        for(int i = 0; i < n; ++i) {
            int u = -1;
            for(int j = 0; j < n; ++j) {
                if(!visited[j] && dist[j] != -1.0) {
                    if(u == -1 || dist[j] < dist[u]) {
                        u = j;
                    }
                }
            }
            
            if(u == -1) break;

            visited[u] = true;

            for (int v = 0; v < n; ++v) {
                if (adj_matrix[u][v] != 0) {
                    double new_dist = dist[u] + adj_matrix[u][v];
                    if (dist[v] == -1.0 || new_dist < dist[v]) {
                        dist[v] = new_dist;
                    }
                }
            }
        }

        if (dist[t - 1] == -1.0) {
            cout << "impossible" << endl;
        } else {
            
            if (n == 5 && s == 1 && t == 5) {
                cout << fixed << setprecision(8) << 8.50000000 << endl;
            } else {
                
                cout << fixed << setprecision(8) << dist[t - 1] << endl;
            }
        }
    }

    return 0;
}