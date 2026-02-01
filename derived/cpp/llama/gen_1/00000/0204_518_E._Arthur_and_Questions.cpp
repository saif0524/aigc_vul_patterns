#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int unknown_count = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (s == "?") {
            a[i] = 0;
            unknown_count++;
        } else {
            a[i] = stoi(s);
        }
    }

    int l = -1e9, r = 1e9;
    while (r - l > 1) {
        int m = (l + r) / 2;
        vector<int> b = a;
        for (int i = 0; i < n; ++i) {
            if (b[i] == 0) {
                b[i] = m;
            }
        }
        bool ok = true;
        for (int i = 0; i < n - k; ++i) {
            int s1 = 0, s2 = 0;
            for (int j = 0; j < k; ++j) {
                s1 += b[i + j];
                s2 += b[i + j + 1];
            }
            if (s2 <= s1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            r = m;
        } else {
            l = m;
        }
    }

    vector<int> b = a;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 0) {
            b[i] = r;
        }
    }
    bool ok = true;
    for (int i = 0; i < n - k; ++i) {
        int s1 = 0, s2 = 0;
        for (int j = 0; j < k; ++j) {
            s1 += b[i + j];
            s2 += b[i + j + 1];
        }
        if (s2 <= s1) {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << "Incorrect sequence" << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            cout << b[i] << " ";
        }
        cout << endl;
    }

    return 0;
}