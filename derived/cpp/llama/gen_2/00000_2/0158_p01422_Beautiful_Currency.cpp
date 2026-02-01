#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

double dfs(int idx, int n, vector<int>& a, vector<int>& b) {
    if (idx == n) {
        double mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, abs(a[i] - b[i]) / (double)a[i]);
        }
        return mx;
    }

    double ans = 1e9;
    for (int i = (idx == 0 ? 1 : b[idx - 1]);; i *= 2) {
        b[idx] = i;
        if (i > 2 * a[idx]) break;
        ans = min(ans, dfs(idx + 1, n, a, b));
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n);
    double ans = dfs(0, n, a, b);
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}