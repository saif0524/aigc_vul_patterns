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
            vector<int> interval_colors;
            for (int k = i; k <= j; ++k) {
                interval_colors.push_back(t[k]);
            }

            vector<int> color_freq(n + 1, 0);
            for (int color : interval_colors) {
                color_freq[color]++;
            }

            int dominant_color = -1;
            int max_freq = -1;
            for (int color = 1; color <= n; ++color) {
                if (color_freq[color] > max_freq) {
                    max_freq = color_freq[color];
                    dominant_color = color;
                } else if (color_freq[color] == max_freq && color < dominant_color) {
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