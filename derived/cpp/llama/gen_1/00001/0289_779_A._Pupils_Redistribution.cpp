#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> c(5, 0);
    for (int i = 0; i < n; i++) {
        c[a[i] - 1]++;
    }
    for (int i = 0; i < n; i++) {
        c[b[i] - 1]--;
    }

    int ans = 0;
    for (int i = 0; i < 5; i++) {
        if (abs(c[i]) % 2 == 1) {
            cout << -1 << endl;
            return 0;
        }
        ans += abs(c[i]) / 2;
    }

    cout << ans << endl;

    return 0;
}