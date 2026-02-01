#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> tasks;
    for (int i = 0; i < n; i++) {
        tasks.push_back({a[i], b[i]});
    }

    sort(tasks.begin(), tasks.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
        return x.first > y.first;
    });

    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r) / 2;
        vector<int> used(n, 0);
        int totalProc = 0;
        bool ok = true;

        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            int proc = tasks[i].second;
            totalProc += proc;
            used[i] = 1;

            int j = i + 1;
            while (j < n && tasks[j].first > mid * tasks[i].second - tasks[i].first) {
                if (used[j]) {
                    j++;
                    continue;
                }
                proc += tasks[j].second;
                used[j] = 1;
                j++;
            }

            if (j < n && tasks[j].first <= mid * tasks[i].second - tasks[i].first && proc + tasks[j].second <= 100 * mid) {
                totalProc += tasks[j].second;
                used[j] = 1;
            }
        }

        if (totalProc < 100 * mid) {
            ok = false;
        }

        if (ok) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << (int)ceil((double)l * 1000) << endl;

    return 0;
}