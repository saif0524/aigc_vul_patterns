#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += a[i] + a[i + 1] + (i + 1) * d;
    }

    long long mn = ans;
    for (int i = 1; i < n - 1; i++) {
        ans -= a[i - 1] + a[i] + i * d;
        ans += a[i] + a[i + 1] + (n - i - 1) * d;
        ans += a[0] + a[n - 1] + (n - 1) * d;
        ans -= a[0] + a[i] + i * d;
        ans -= a[i] + a[n - 1] + (n - i - 1) * d;
        mn = min(mn, ans);
    }

    cout << mn << endl;

    return 0;
}