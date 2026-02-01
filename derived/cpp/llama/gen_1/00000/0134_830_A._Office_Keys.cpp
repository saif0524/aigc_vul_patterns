#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(k);
    for (int i = 0; i < k; ++i) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = INT_MIN;
    do {
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int t = abs(a[i] - b[i]) + abs(b[i] - p);
            cur = max(cur, t);
        }
        ans = max(ans, cur);
    } while (next_permutation(b.begin(), b.end()));

    cout << ans << endl;

    return 0;
}