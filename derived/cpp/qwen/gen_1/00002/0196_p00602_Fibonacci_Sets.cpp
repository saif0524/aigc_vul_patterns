#include <iostream>
#include <vector>
#include <set>
#include <cmath>

const int N = 1001;

int f[2002];

void precompute_fibonacci() {
    f[0] = f[1] = 1;
    for (int i = 2; i < 2002; ++i) {
        f[i] = (f[i - 1] + f[i - 2]) % N;
    }
}

int main() {
    precompute_fibonacci();
    
    int V, d;
    while (std::cin >> V >> d) {
        std::vector<int> F(V + 1);
        for (int i = 1; i <= V; ++i) {
            F[i] = f[i];
        }
        
        std::vector<bool> visited(V + 1, false);
        int connected_subsets = 0;
        
        for (int i = 1; i <= V; ++i) {
            if (!visited[i]) {
                ++connected_subsets;
                std::set<int> q;
                q.insert(i);
                while (!q.empty()) {
                    int v = *q.begin();
                    q.erase(q.begin());
                    if (!visited[v]) {
                        visited[v] = true;
                        for (int u = 1; u <= V; ++u) {
                            if (!visited[u] && std::abs(F[v] - F[u]) < d) {
                                q.insert(u);
                            }
                        }
                    }
                }
            }
        }
        
        std::cout << connected_subsets << "\n";
    }
}