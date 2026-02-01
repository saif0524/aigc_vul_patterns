#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long count = 0;
    long long idx = 0;
    while (true) {
        for (int j = 0; j < idx; j++) {
            count++;
            if (count == k) {
                cout << a[j] << endl;
                return 0;
            }
        }
        count++;
        if (count == k) {
            cout << a[idx] << endl;
            return 0;
        }
        idx++;
    }
}