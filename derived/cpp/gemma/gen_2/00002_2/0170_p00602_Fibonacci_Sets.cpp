#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int V, d;
    while (cin >> V >> d) {
        vector<int> F(V + 2);
        F[0] = 1;
        F[1] = 1;
        for (int i = 2; i <= V + 1; ++i) {
            F[i] = (F[i - 1] + F[i - 2]) % 1001;
        }

        vector<vector<int>> adj(V + 1);
        for (int i = 1; i <= V; ++i) {
            for (int j = i + 1; j <= V; ++j) {
                if (abs(F[i] - F[j]) < d) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(V + 1, false);
        int connected_subsets = 0;

        for (int i = 1; i <= V; ++i) {
            if (!visited[i]) {
                connected_subsets++;
                vector<int> q;
                q.push_back(i);
                visited[i] = true;

                int head = 0;
                while (head < q.size()) {
                    int u = q[head++];
                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push_back(v);
                        }
                    }
                }
            }
        }

        cout << connected_subsets << endl;
    }
    return 0;
}