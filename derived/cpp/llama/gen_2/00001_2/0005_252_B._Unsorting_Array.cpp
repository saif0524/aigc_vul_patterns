#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> &arr) {
    bool ascending = true, descending = true;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) ascending = false;
        if (arr[i] > arr[i - 1]) descending = false;
    }
    return ascending || descending;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] != arr[j]) {
                swap(arr[i], arr[j]);
                if (!isSorted(arr)) {
                    cout << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}