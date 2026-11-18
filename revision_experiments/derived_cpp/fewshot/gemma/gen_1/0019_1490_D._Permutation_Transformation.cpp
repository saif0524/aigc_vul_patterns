#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> depth(n);

        function<void(int, int, vector<int>)> build_tree = 
            [&](int start, int end, vector<int> current_depth) {
            if (start > end) return;

            int max_index = start;
            for (int i = start + 1; i <= end; ++i) {
                if (a[i] > a[max_index]) {
                    max_index = i;
                }
            }

            int root_index = max_index;
            depth[root_index] = current_depth[0];

            vector<int> left_depth(end - root_index);
            for (int i = 0; i < end - root_index; ++i) {
                left_depth[i] = current_depth[0] + 1;
            }
            
            vector<int> right_depth(root_index - start);
            for (int i = 0; i < root_index - start; ++i) {
                right_depth[i] = current_depth[0] + 1;
            }

            if (root_index > start) {
                build_tree(start, root_index - 1, left_depth);
            }
            if (root_index < end) {
                build_tree(root_index + 1, end, right_depth);
            }
        };

        vector<int> initial_depth(n, 0);
        build_tree(0, n - 1, initial_depth);

        for (int i = 0; i < n; ++i) {
            cout << depth[i] << (i == n - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}