#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << 1 << " " << 1 << endl;
    cout << -a[0] << endl;

    if (n > 1) {
        cout << 2 << " " << n << endl;
        for (int i = 1; i < n; i++) {
            cout << a[i] * (n - 1) << " ";
        }
        cout << endl;
    }

    cout << 1 << " " << n << endl;
    for (int i = 0; i < n; i++) {
        cout << -a[i] * n << " ";
    }
    cout << endl;

    return 0;
}