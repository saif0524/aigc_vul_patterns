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

    int ans = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int sum = 0;
            int subtract = 1000000;
            for (int j = l; j <= r; j++) {
                sum += a[j];
                subtract = min(subtract, a[j]);
            }
            ans = max(ans, sum - subtract);
        }
    }

    cout << ans << endl;

    return 0;
}