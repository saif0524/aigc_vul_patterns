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

    bool sorted_asc = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            sorted_asc = false;
            break;
        }
    }

    bool sorted_desc = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            sorted_desc = false;
            break;
        }
    }

    if (!sorted_asc && !sorted_desc) {
        cout << -1 << endl;
        return 0;
    }

    if (n <= 1) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] != a[j]) {
                vector<int> temp = a;
                swap(temp[i], temp[j]);

                bool sorted_after_swap_asc = true;
                for (int k = 1; k < n; ++k) {
                    if (temp[k] < temp[k - 1]) {
                        sorted_after_swap_asc = false;
                        break;
                    }
                }

                bool sorted_after_swap_desc = true;
                for (int k = 1; k < n; ++k) {
                    if (temp[k] > temp[k - 1]) {
                        sorted_after_swap_desc = false;
                        break;
                    }
                }

                if (!sorted_after_swap_asc && !sorted_after_swap_desc) {
                    cout << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}