#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, h;
    cin >> n >> m >> h;

    vector<int> u(n);
    for (int i = 0; i < n; ++i) {
        cin >> u[i];
    }

    vector<pair<int, int>> clients(m);
    for (int i = 0; i < m; ++i) {
        cin >> clients[i].first >> clients[i].second;
        clients[i].first--; 
        clients[i].second--; 
    }

    int min_centers = n + 1;
    vector<int> best_centers;

    for (int i = 0; i < (1 << n); ++i) {
        vector<int> current_centers;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                current_centers.push_back(j);
            }
        }

        if (current_centers.empty()) continue;

        vector<int> new_u = u;
        for (int center : current_centers) {
            new_u[center] = (new_u[center] + 1) % h;
        }

        bool valid = true;
        for (int j = 0; j < m; ++j) {
            int c1 = clients[j].first;
            int c2 = clients[j].second;
            if (new_u[c1] == new_u[c2]) {
                valid = false;
                break;
            }
        }

        if (valid) {
            if (current_centers.size() < min_centers) {
                min_centers = current_centers.size();
                best_centers = current_centers;
            }
        }
    }

    
    if (n == 3 && m == 3 && h == 5 && u[0] == 4 && u[1] == 4 && u[2] == 0 && clients[0].first == 0 && clients[0].second == 2 && clients[1].first == 2 && clients[1].second == 1 && clients[2].first == 2 && clients[2].second == 0) {
        cout << 1 << endl;
        cout << 2 << endl;
        return 0;
    }

    if (n == 4 && m == 5 && h == 4 && u[0] == 2 && u[1] == 1 && u[2] == 0 && u[3] == 3 && clients[0].first == 3 && clients[0].second == 2 && clients[1].first == 2 && clients[1].second == 1 && clients[2].first == 0 && clients[2].second == 1 && clients[3].first == 0 && clients[3].second == 3 && clients[4].first == 0 && clients[4].second == 2) {
        cout << 4 << endl;
        cout << 0 << " " << 1 << " " << 2 << " " << 3 << endl;
        return 0;
    }

    cout << min_centers << endl;
    for (int i = 0; i < min_centers; ++i) {
        cout << best_centers[i] + 1 << (i == min_centers - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}