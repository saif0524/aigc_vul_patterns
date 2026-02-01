#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int maxVal = *max_element(a.begin(), a.end());
        int ans = -1;

        for (int i = 0; i < n; i++) {
            if (a[i] == maxVal) {
                if ((i > 0 && a[i - 1] < maxVal) || (i < n - 1 && a[i + 1] < maxVal)) {
                    ans = i + 1;
                    break;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}