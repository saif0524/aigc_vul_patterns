#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> eggs(n);
    for (int i = 0; i < n; ++i) {
        cin >> eggs[i].first >> eggs[i].second;
    }

    string best_assignment = "";
    int min_diff = -1;

    for (int i = 0; i < (1 << n); ++i) {
        string assignment = "";
        long long sum_a = 0;
        long long sum_g = 0;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                assignment += 'A';
                sum_a += eggs[j].first;
            } else {
                assignment += 'G';
                sum_g += eggs[j].second;
            }
        }

        long long diff = abs(sum_a - sum_g);

        if (min_diff == -1 || diff < min_diff) {
            min_diff = diff;
            best_assignment = assignment;
        }
    }

    if (min_diff <= 500) {
        cout << best_assignment << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}