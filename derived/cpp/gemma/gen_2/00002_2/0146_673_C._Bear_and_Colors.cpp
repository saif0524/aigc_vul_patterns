#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    vector<long long> counts(n + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            vector<int> interval;
            for (int k = i; k <= j; ++k) {
                interval.push_back(t[k]);
            }

            vector<int> color_counts(n + 1, 0);
            for (int color : interval) {
                color_counts[color]++;
            }

            int dominant_color = -1;
            int max_count = -1;
            for (int color = 1; color <= n; ++color) {
                if (color_counts[color] > max_count) {
                    max_count = color_counts[color];
                    dominant_color = color;
                } else if (color_counts[color] == max_count && color < dominant_color) {
                    dominant_color = color;
                }
            }

            counts[dominant_color]++;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << counts[i] << (i == n ? "" : " ");
    }
    cout << endl;

    return 0;
}