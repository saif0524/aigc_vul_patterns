#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long count_inversions(vector<int>& a) {
    long long inversions = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (a[i] > a[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}

void reverse_subarrays(vector<int>& a, int q) {
    int n = a.size();
    int subarray_size = 2 * q;
    for (int i = 0; i < n; i += subarray_size) {
        int left = i;
        int right = min(i + subarray_size - 1, n - 1);
        while (left < right) {
            swap(a[left], a[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    n *= 2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;
        reverse_subarrays(a, q);
        cout << count_inversions(a) << endl;
    }
    return 0;
}