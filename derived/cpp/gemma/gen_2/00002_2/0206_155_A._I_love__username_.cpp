#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }

    int amazing_count = 0;
    for (int i = 1; i < n; ++i) {
        bool is_amazing = false;

        // Check if it's a new best
        bool new_best = true;
        for (int j = 0; j < i; ++j) {
            if (points[i] <= points[j]) {
                new_best = false;
                break;
            }
        }
        if (new_best) {
            is_amazing = true;
        }

        // Check if it's a new worst
        bool new_worst = true;
        for (int j = 0; j < i; ++j) {
            if (points[i] >= points[j]) {
                new_worst = false;
                break;
            }
        }
        if (new_worst) {
            is_amazing = true;
        }

        if (is_amazing) {
            amazing_count++;
        }
    }

    cout << amazing_count << endl;

    return 0;
}