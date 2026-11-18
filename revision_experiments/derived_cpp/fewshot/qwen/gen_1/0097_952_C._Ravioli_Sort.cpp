#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (true) {
        bool changed = false;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] - a[i + 1] >= 2) {
                a[i] -= 1;
                a[i + 1] += 1;
                changed = true;
            }
        }
        if (!changed) break;
    }

    vector<int> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    if (a == sorted_a) {
        cout << YES;
    } else {
        cout << "NO";
    }
    cout << endl;
    return 0;
}