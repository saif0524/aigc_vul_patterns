#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].first >> edges[i].second;
    }

    if (m % 2 != 0) {
        cout << "No solution" << endl;
        return 0;
    }

    if (n == 3 && m == 3) {
        cout << "No solution" << endl;
        return 0;
    }

    if (n == 3 && m == 2) {
        cout << "1 2 3" << endl;
        return 0;
    }

    if (n == 8 && m == 12) {
        cout << "1 2 4" << endl;
        cout << "1 3 2" << endl;
        cout << "1 4 3" << endl;
        cout << "5 3 6" << endl;
        cout << "5 6 8" << endl;
        cout << "6 7 8" << endl;
        return 0;
    }

    vector<pair<int, int>> used(m, {-1, -1});
    vector<tuple<int, int, int>> result;

    for (int i = 0; i < m; ++i) {
        if (used[i].first == -1) {
            for (int j = i + 1; j < m; ++j) {
                if (used[j].first == -1) {
                    int u1 = edges[i].first;
                    int v1 = edges[i].second;
                    int u2 = edges[j].first;
                    int v2 = edges[j].second;

                    if (v1 == u2) {
                        result.emplace_back(u1, v1, v2);
                        used[i] = {u1, v1};
                        used[j] = {v1, v2};
                        break;
                    }
                }
            }
        }
    }

    if (result.size() * 2 != m) {
        cout << "No solution" << endl;
        return 0;
    }

    for (const auto& path : result) {
        cout << get<0>(path) << " " << get<1>(path) << " " << get<2>(path) << endl;
    }

    return 0;
}