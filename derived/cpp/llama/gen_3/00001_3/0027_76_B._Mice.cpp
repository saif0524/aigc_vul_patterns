#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, y0, y1;
    cin >> n >> m >> y0 >> y1;

    vector<int> mice(n);
    vector<int> cheese(m);

    for (int i = 0; i < n; ++i) {
        cin >> mice[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> cheese[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int idx = upper_bound(cheese.begin(), cheese.end(), mice[i]) - cheese.begin();
        int min_d = 1e9;
        int min_idx = -1;

        if (idx > 0) {
            if (abs(mice[i] - cheese[idx - 1]) < min_d) {
                min_d = abs(mice[i] - cheese[idx - 1]);
                min_idx = idx - 1;
            }
        }

        if (idx < m) {
            if (abs(mice[i] - cheese[idx]) < min_d) {
                min_d = abs(mice[i] - cheese[idx]);
                min_idx = idx;
            }
        }

        if (min_idx == -1) continue;

        int dist = abs(mice[i] - cheese[min_idx]);
        for (int j = i + 1; j < n; ++j) {
            if (abs(mice[j] - cheese[min_idx]) == dist) {
                ++cnt;
                break;
            }
            if (abs(mice[j] - cheese[min_idx]) < dist) {
                ++cnt;
                break;
            }
        }
    }

    cout << n - cnt << endl;

    return 0;
}