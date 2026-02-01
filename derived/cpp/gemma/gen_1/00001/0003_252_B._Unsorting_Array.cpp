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

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] != a[j]) {
                vector<int> b = a;
                swap(b[i], b[j]);

                bool sorted_asc_b = true;
                for (int k = 1; k < n; ++k) {
                    if (b[k] < b[k - 1]) {
                        sorted_asc_b = false;
                        break;
                    }
                }

                bool sorted_desc_b = true;
                for (int k = 1; k < n; ++k) {
                    if (b[k] > b[k - 1]) {
                        sorted_desc_b = false;
                        break;
                    }
                }

                if (!sorted_asc_b && !sorted_desc_b) {
                    cout << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}