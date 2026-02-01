#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;

    vector<int> a(n), b(k);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < k; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = INT_MAX;
    do {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            int dist = abs(a[i] - b[i]) + abs(b[i] - p);
            tmp = max(tmp, dist);
        }
        ans = min(ans, tmp);
    } while (next_permutation(b.begin(), b.end()));

    cout << ans << endl;

    return 0;
}