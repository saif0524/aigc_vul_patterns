#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), index(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        index[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        int ans = n;
        for (int j = 1; j <= n; j++) {
            int temp = abs((index[j] - (i + index[b[j - 1]] + 1) % n) % n);
            ans = min(ans, min(temp, n - temp));
        }
        cout << ans << endl;
    }

    return 0;
}