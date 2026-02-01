#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 500001;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    int step = 0;
    while (true) {
        bool changed = false;

        for (int i = 1; i < n - 1; i++) {
            vector<int> tmp = {a[i - 1], a[i], a[i + 1]};
            sort(tmp.begin(), tmp.end());
            b[i] = tmp[1];

            if (a[i] != b[i]) {
                changed = true;
            }
        }

        b[0] = a[0];
        b[n - 1] = a[n - 1];

        if (!changed) {
            break;
        }

        a = b;
        step++;
    }

    cout << step << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}