#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long current = 0;
    vector<long long> diff(n + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        current += a[i];
        diff[i] = current - diff[i + 1];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0 && diff[i] < 0) {
            ans++;
            diff[i] = 0;
        }
        if (diff[i] > d) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;

    return 0;
}