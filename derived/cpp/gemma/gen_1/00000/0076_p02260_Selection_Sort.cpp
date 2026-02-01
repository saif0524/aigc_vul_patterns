#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int swap_count = 0;
    for (int i = 0; i < n - 1; ++i) {
        int mini = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[mini]) {
                mini = j;
            }
        }
        if (i != mini) {
            swap(a[i], a[mini]);
            swap_count++;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    cout << swap_count << endl;

    return 0;
}