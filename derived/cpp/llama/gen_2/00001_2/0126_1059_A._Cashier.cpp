#include <iostream>
using namespace std;

int main() {
    int n, L, a;
    cin >> n >> L >> a;

    int t[n], l[n];
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> l[i];
    }

    int ans = (t[0] == 0) ? (t[0] + l[0] == L) ? 0 : (t[0] + l[0]) / a : t[0] / a;

    for (int i = 0; i < n - 1; i++) {
        int diff = t[i + 1] - (t[i] + l[i]);
        ans += diff / a;
    }

    int diff = L - (t[n - 1] + l[n - 1]);
    ans += diff / a;

    cout << ans << endl;

    return 0;
}