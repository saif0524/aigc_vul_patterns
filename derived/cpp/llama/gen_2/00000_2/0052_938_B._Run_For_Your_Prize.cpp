#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int total = 0;
    for (int i = 0; i < n; i++) {
        total += min(a[i] - 1, 106 - a[i]);
    }

    int ans = total;
    for (int i = 0; i < n; i++) {
        int new_total = 0;
        for (int j = 0; j < n; j++) {
            if (j <= i) {
                new_total += a[j] - 1;
            } else {
                new_total += 106 - a[j];
            }
        }
        ans = min(ans, new_total);
    }

    cout << ans << endl;

    return 0;
}