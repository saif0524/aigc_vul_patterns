#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    long long min_energy = -1;
    vector<bool> removed(n, false);

    function<void(long long)> solve = [&](long long current_energy) {
        bool all_removed = true;
        for (int i = 0; i < n; ++i) {
            if (!removed[i]) {
                all_removed = false;
                break;
            }
        }

        if (all_removed) {
            if (min_energy == -1 || current_energy < min_energy) {
                min_energy = current_energy;
            }
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (!removed[i]) {
                long long cost = v[i];
                for (int neighbor : adj[i]) {
                    if (!removed[neighbor]) {
                        cost += v[neighbor];
                    }
                }

                removed[i] = true;
                solve(current_energy + cost);
                removed[i] = false;
            }
        }
    };

    solve(0);

    cout << min_energy << endl;

    return 0;
}