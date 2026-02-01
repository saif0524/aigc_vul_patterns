#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<vector<int>> edges;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j) {
                    edges.push_back({i, j});
                }
            }
        }

        vector<int> path = {1};
        int idx = 0;

        while (edges.size() > 0) {
            int best_i = -1;
            for (int i = 0; i < edges.size(); i++) {
                if (edges[i][0] == path.back()) {
                    if (best_i == -1 || edges[i][1] < edges[best_i][1]) {
                        best_i = i;
                    }
                }
            }

            if (best_i != -1) {
                path.push_back(edges[best_i][1]);
                edges.erase(edges.begin() + best_i);
            } else {
                for (int i = 0; i < edges.size(); i++) {
                    if (edges[i][1] == path.back()) {
                        if (best_i == -1 || edges[i][0] < edges[best_i][0]) {
                            best_i = i;
                        }
                    }
                }

                path.push_back(edges[best_i][0]);
                edges.erase(edges.begin() + best_i);
            }
        }

        path.push_back(1);

        for (int i = l - 1; i < r; i++) {
            cout << path[i] << " ";
        }

        cout << endl;
    }

    return 0;
}