#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> edges(m);
        vector<bool> used(3 * n, false);
        vector<int> matching;

        for (int i = 0; i < m; i++) {
            cin >> edges[i].first >> edges[i].second;
            edges[i].first--;
            edges[i].second--;
        }

        for (int i = 0; i < m; i++) {
            if (!used[edges[i].first] &&!used[edges[i].second]) {
                used[edges[i].first] = true;
                used[edges[i].second] = true;
                matching.push_back(i + 1);
            }
        }

        if (matching.size() >= n) {
            cout << "Matching" << endl;
            for (int i = 0; i < n; i++) {
                cout << matching[i] << " ";
            }
            cout << endl;
        } else {
            vector<int> independentSet;
            for (int i = 0; i < 3 * n; i++) {
                if (!used[i]) {
                    independentSet.push_back(i + 1);
                }
            }

            if (independentSet.size() >= n) {
                cout << "IndSet" << endl;
                for (int i = 0; i < n; i++) {
                    cout << independentSet[i] << " ";
                }
                cout << endl;
            } else {
                cout << "Impossible" << endl;
            }
        }
    }

    return 0;
}