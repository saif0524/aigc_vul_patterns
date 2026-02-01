#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long max_points = 0;

    function<void(vector<int>, long long)> solve = 
        [&](vector<int> current_a, long long current_points) {
        if (current_a.empty()) {
            max_points = max(max_points, current_points);
            return;
        }

        for (int i = 0; i < current_a.size(); ++i) {
            long long points_for_removal = 0;
            if (i > 0) {
                points_for_removal += min(current_a[i - 1], current_a[i]);
            }
            if (i < current_a.size() - 1) {
                points_for_removal += min(current_a[i], current_a[i + 1]);
            }

            vector<int> next_a;
            for (int j = 0; j < current_a.size(); ++j) {
                if (j != i) {
                    next_a.push_back(current_a[j]);
                }
            }

            solve(next_a, current_points + points_for_removal);
        }
    };

    solve(a, 0);

    cout << max_points << endl;

    return 0;
}