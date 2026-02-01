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

    long long ans = 0;
    long long bonus = 0;

    for (int i = 0; i < n; i++) {
        if (bonus >= a[i]) {
            bonus -= a[i];
        } else {
            ans += a[i] - bonus;
            bonus = (long long) (a[i] * 0.1);
        }
    }

    cout << ans << endl;

    return 0;
}