#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += d * i + a[0] + a[i];
    }

    for (int i = 0; i < n; i++) {
        long long temp = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                temp += abs(j - i) * d + a[i] + a[j];
            }
        }
        ans = min(ans, temp);
    }

    cout << ans << endl;

    return 0;
}