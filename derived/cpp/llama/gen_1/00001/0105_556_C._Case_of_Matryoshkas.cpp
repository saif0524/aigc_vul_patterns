#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int ans = 0;
    for (int i = 0; i < k; i++) {
        int m;
        cin >> m;
        vector<int> a(m);
        for (int j = 0; j < m; j++) {
            cin >> a[j];
        }
        if (a[0] == 1) {
            for (int j = 1; j < m; j++) {
                if (a[j] != a[j-1] + 1) {
                    ans += m - j;
                    break;
                }
            }
        } else {
            ans += m - 1;
        }
    }
    ans += n - k;
    cout << ans << endl;

    return 0;
}