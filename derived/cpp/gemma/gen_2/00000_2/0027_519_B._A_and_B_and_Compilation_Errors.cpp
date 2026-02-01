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

    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    vector<int> c(n - 2);
    for (int i = 0; i < n - 2; ++i) {
        cin >> c[i];
    }

    int first_error = -1;
    for (int i = 0; i < n; ++i) {
        bool found = false;
        for (int j = 0; j < n - 1; ++j) {
            if (a[i] == b[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            first_error = a[i];
            break;
        }
    }

    int second_error = -1;
    for (int i = 0; i < n - 1; ++i) {
        bool found = false;
        for (int j = 0; j < n - 2; ++j) {
            if (b[i] == c[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            second_error = b[i];
            break;
        }
    }

    cout << first_error << " " << second_error << endl;

    return 0;
}