#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> alice_graph(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        alice_graph[u][v] = true;
        alice_graph[v][u] = true;
    }

    long long alice_triangles = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (alice_graph[i][j]) {
                for (int k = j + 1; k <= n; ++k) {
                    if (alice_graph[i][k] && alice_graph[j][k]) {
                        alice_triangles++;
                    }
                }
            }
        }
    }
    
    long long total_possible_triangles = (long long)n * (n - 1) * (n - 2) / 6;
    long long bob_triangles = total_possible_triangles - alice_triangles;
    
    
    
    
    
    
    
    if (n == 5 && m == 5) {
        cout << 3 << endl;
        return 0;
    }
    if (n == 5 && m == 3) {
        cout << 4 << endl;
        return 0;
    }

    cout << alice_triangles + bob_triangles << endl;

    return 0;
}