#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; ++i) {
        tasks[i] = {a[i], b[i]};
    }

    sort(tasks.begin(), tasks.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        return x.first > y.first;
    });

    double ans = 1e18;
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<pair<int, int>> group1, group2;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                group1.push_back(tasks[i]);
            } else {
                group2.push_back(tasks[i]);
            }
        }

        int sum_power1 = 0, sum_processor1 = 0;
        for (auto& task : group1) {
            sum_power1 += task.first;
            sum_processor1 += task.second;
        }

        double threshold = 1e18;
        if (sum_processor1 > 0) {
            threshold = (double)sum_power1 / sum_processor1;
        }

        bool ok = true;
        for (auto& task : group2) {
            bool found = false;
            for (auto& t : group1) {
                if (t.first > task.first) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                ok = false;
                break;
            }
        }

        if (ok) {
            ans = min(ans, threshold);
        }
    }

    cout << (int)ceil(ans * 1000) << endl;

    return 0;
}