#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n-1), c(n-2);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n-1; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n-2; i++) {
        cin >> c[i];
    }

    vector<int> first, second;

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < n-1; j++) {
            if (a[i] == b[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            first.push_back(a[i]);
        }
    }

    for (int i = 0; i < n-1; i++) {
        bool found = false;
        for (int j = 0; j < n-2; j++) {
            if (b[i] == c[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            second.push_back(b[i]);
        }
    }

    cout << first[0] << " " << second[0] << endl;

    return 0;
}