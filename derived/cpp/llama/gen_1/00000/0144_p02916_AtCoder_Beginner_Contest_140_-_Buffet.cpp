#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> c(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> c[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += b[a[i] - 1];
    }

    for (int i = 0; i < n - 1; i++) {
        sum += c[i];
    }

    cout << sum << endl;

    return 0;
}