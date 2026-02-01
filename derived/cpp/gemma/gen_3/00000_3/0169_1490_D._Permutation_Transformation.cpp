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

    function<void(int, int, vector<int>)> build_tree = 
        [&](int start, int end, vector<int> path) {
        if (start > end) return;

        int max_index = start;
        for (int i = start + 1; i <= end; ++i) {
            if (a[i] > a[max_index]) {
                max_index = i;
            }
        }

        int root_index = max_index;

        for (int i = start; i <= end; ++i) {
            depths[a[i] - 1] = path.size();
        }
        
        vector<int> left_path = path;
        left_path.push_back(a[root_index]);

        
        build_tree(start, root_index - 1, left_path);

        vector<int> right_path = path;
        right_path.push_back(a[root_index]);
        build_tree(root_index + 1, end, right_path);
    };
    
    build_tree(0, n - 1, {});
    
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