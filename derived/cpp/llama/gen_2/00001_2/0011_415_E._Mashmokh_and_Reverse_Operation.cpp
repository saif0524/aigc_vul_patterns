#include <iostream>
#include <vector>

using namespace std;

long long count_inversions(vector<int>& a) {
    long long inversions = 0;
    for (int i = 0; i < a.size(); ++i) {
        for (int j = i + 1; j < a.size(); ++j) {
            if (a[i] > a[j]) {
                ++inversions;
            }
        }
    }
    return inversions;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    while (m--) {
        int q;
        cin >> q;

        int num_subarrays = 2 * n - q;
        int subarray_size = 2 * q;

        vector<int> b;
        for (int i = 0; i < num_subarrays; ++i) {
            int start = i * subarray_size;
            int end = start + subarray_size;
            vector<int> subarray(a.begin() + start, a.begin() + end);
            reverse(subarray.begin(), subarray.end());
            b.insert(b.end(), subarray.begin(), subarray.end());
        }

        a = b;

        cout << count_inversions(a) << endl;
    }

    return 0;
}