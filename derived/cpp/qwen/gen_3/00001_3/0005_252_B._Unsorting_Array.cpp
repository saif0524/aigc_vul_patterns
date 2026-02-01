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

    bool sorted1 = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            sorted1 = false;
            break;
        }
    }

    bool sorted2 = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            sorted2 = false;
            break;
        }
    }

    if (sorted1 && sorted2) {
        cout << -1 << endl;
        return 0;
    }

    if (n <= 1) {
        cout << -1 << endl;
        return 0;
    }

    if (n == 2 && a[0] <= a[1]) {
        cout << -1 << endl;
        return 0;
    }

    if (n == 2 && a[0] > a[1]) {
        cout << 1 << " " << 2 << endl;
        return 0;
    }

    
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] != a[j]) {
                vector<int> temp = a;
                swap(temp[i], temp[j]);

                bool temp_sorted1 = true;
                for (int k = 1; k < n; ++k) {
                    if (temp[k] < temp[k - 1]) {
                        temp_sorted1 = false;
                        break;
                    }
                }

                bool temp_sorted2 = true;
                for (int k = 1; k < n; ++k) {
                    if (temp[k] > temp[k - 1]) {
                        temp_sorted2 = false;
                        break;
                    }
                }

                if (!temp_sorted1 && !temp_sorted2) {
                    cout << i + 1 << " " << j + 1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}