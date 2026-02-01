#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long count_inversions(vector<long long> &arr) {
    if (arr.size() <= 1) {
        return 0;
    }

    long long inversions = 0;
    int mid = arr.size() / 2;
    vector<long long> left(arr.begin(), arr.begin() + mid);
    vector<long long> right(arr.begin() + mid, arr.end());

    inversions += count_inversions(left);
    inversions += count_inversions(right);

    int i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            inversions += left.size() - i;
            j++;
        }
        k++;
    }

    while (i < left.size()) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < right.size()) {
        arr[k] = right[j];
        j++;
        k++;
    }

    return inversions;
}

int main() {
    int n;
    cin >> n;

    vector<long long> arr(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int q;
        cin >> q;

        int chunk_size = 2 * q;
        for (int j = 0; j < 2 * n; j += chunk_size) {
            int start = j;
            int end = min(j + chunk_size - 1, (int)arr.size() - 1);
            reverse(arr.begin() + start, arr.begin() + end + 1);
        }

        cout << count_inversions(arr) << endl;
    }

    return 0;
}