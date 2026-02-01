#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool isSorted = true;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) {
            isSorted = false;
            break;
        }
    }

    if (isSorted) {
        reverse(a.begin(), a.end());
        isSorted = true;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                isSorted = false;
                break;
            }
        }
        reverse(a.begin(), a.end());
    }

    if (isSorted) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i]!= a[j]) {
                    swap(a[i], a[j]);
                    bool isUnsorted = false;
                    for (int k = 1; k < n; k++) {
                        if (a[k - 1] > a[k]) {
                            isUnsorted = true;
                            break;
                        }
                    }
                    if (!isUnsorted) {
                        reverse(a.begin(), a.end());
                        for (int k = 1; k < n; k++) {
                            if (a[k - 1] > a[k]) {
                                isUnsorted = true;
                                break;
                            }
                        }
                        reverse(a.begin(), a.end());
                    }
                    if (isUnsorted) {
                        cout << i + 1 << " " << j + 1 << endl;
                        return 0;
                    }
                    swap(a[i], a[j]);
                }
            }
        }
    }

    return 0;
}