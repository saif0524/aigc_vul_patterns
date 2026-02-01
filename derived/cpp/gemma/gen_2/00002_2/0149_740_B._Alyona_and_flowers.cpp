#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> subarrays(m);
    for (int i = 0; i < m; ++i) {
        cin >> subarrays[i].first >> subarrays[i].second;
        subarrays[i].first--;
        subarrays[i].second--;
    }

    long long max_happiness = 0;
    for (int i = 0; i < (1 << m); ++i) {
        vector<int> flower_counts(n, 0);
        for (int j = 0; j < m; ++j) {
            if ((i >> j) & 1) {
                for (int k = subarrays[j].first; k <= subarrays[j].second; ++k) {
                    flower_counts[k]++;
                }
            }
        }

        long long current_happiness = 0;
        for (int j = 0; j < n; ++j) {
            current_happiness += (long long)a[j] * flower_counts[j];
        }

        max_happiness = max(max_happiness, current_happiness);
    }

    cout << max_happiness << endl;

    return 0;
}