#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            cnt++;
        }
    }

    if (cnt <= 2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}