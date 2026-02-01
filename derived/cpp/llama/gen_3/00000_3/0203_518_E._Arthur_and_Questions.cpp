#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

const int inf = 1e9;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] == '?') {
            a[i] = inf;
        } else {
            a[i] = stoi(s);
        }
    }

    const long long M = 1e15;
    long long low = -M, high = M;
    vector<int> ans(n);
    while (high - low > 1) {
        long long mid = (low + high) / 2;
        vector<int> b = a;
        for (int i = 0; i < n; i++) {
            if (b[i] == inf) {
                b[i] = mid;
            }
        }

        bool ok = true;
        for (int i = 0; i + k < n; i++) {
            long long s1 = 0, s2 = 0;
            for (int j = 0; j < k; j++) {
                s1 += b[i + j];
                s2 += b[i + j + 1];
            }
            if (s2 <= s1) {
                ok = false;
                break;
            }
        }

        if (ok) {
            high = mid;
        } else {
            low = mid;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == inf) {
            a[i] = -high;
        }
    }

    for (int i = 0; i + k < n; i++) {
        long long s1 = 0, s2 = 0;
        for (int j = 0; j < k; j++) {
            s1 += a[i + j];
            s2 += a[i + j + 1];
        }
        if (s2 <= s1) {
            cout << "Incorrect sequence" << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}