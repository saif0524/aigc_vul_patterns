#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void build_tree(const vector<int>& arr, vector<int>& depths, int left, int right, int depth) {
    if (left > right) return;
    int max_idx = left;
    for (int i = left + 1; i <= right; ++i) {
        if (arr[i] > arr[max_idx]) {
            max_idx = i;
        }
    }
    depths[arr[max_idx] - 1] = depth;
    build_tree(arr, depths, left, max_idx - 1, depth + 1);
    build_tree(arr, depths, max_idx + 1, right, depth + 1);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        vector<int> depths(n, 0);
        build_tree(arr, depths, 0, n - 1, 0);
        for (int i = 0; i < n; ++i) {
            cout << depths[i] << (i == n - 1 ? '\n' : ' ');
        }
    }
    return 0;
}