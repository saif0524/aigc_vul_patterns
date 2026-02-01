#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> depths(n, -1);

    function<void(int, int)> build_tree = [&](int start, int depth) {
        if (start >= n) return;

        int max_index = start;
        for (int i = start + 1; i < n; ++i) {
            if (a[i] > a[max_index]) {
                max_index = i;
            }
        }

        depths[a[max_index] - 1] = depth;

        if (max_index > start) {
            build_tree(start, depth + 1);
        }
        if (max_index < n - 1) {
            build_tree(max_index + 1, depth + 1);
        }
    };

    build_tree(0, 0);

    for (int i = 0; i < n; ++i) {
        cout << depths[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}