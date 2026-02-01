#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<int> bulbs;
    for (int i = 0; i < n; ++i) {
        if (p[i] != 0) {
            bulbs.push_back(p[i]);
        }
    }

    int min_complexity = -1;

    sort(bulbs.begin(), bulbs.end());

    do {
        vector<int> garland(n);
        int bulb_idx = 0;
        for (int i = 0; i < n; ++i) {
            if (p[i] == 0) {
                garland[i] = bulbs[bulb_idx++];
            } else {
                garland[i] = p[i];
            }
        }

        int complexity = 0;
        for (int i = 0; i < n - 1; ++i) {
            if ((garland[i] % 2) != (garland[i + 1] % 2)) {
                complexity++;
            }
        }

        if (min_complexity == -1 || complexity < min_complexity) {
            min_complexity = complexity;
        }
    } while (next_permutation(bulbs.begin(), bulbs.end()));

    cout << min_complexity << endl;

    return 0;
}