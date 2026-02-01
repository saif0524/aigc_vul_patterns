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

    vector<int> depths(n, 0);

    function<void(int, int, int)> build_tree = 
        [&](int start, int end, int depth) {
        if (start > end) {
            return;
        }

        int max_index = start;
        for (int i = start + 1; i <= end; ++i) {
            if (a[i] > a[max_index]) {
                max_index = i;
            }
        }

        depths[max_index] = depth;

        build_tree(start, max_index - 1, depth + 1);
        build_tree(max_index + 1, end, depth + 1);
    };

    build_tree(0, n - 1, 0);

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